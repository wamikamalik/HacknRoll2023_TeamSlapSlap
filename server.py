import paho.mqtt.client as mqtt
import json
import time
import csv
import statistics

data = []
slouch = 0

def on_connect(client, userdata, flags, rc):
    if rc == 0:
        print("Connected.")
        client.subscribe("imu/data")
    else:
        print("Failed to connect. Error code:", rc)

def on_message(client, userdata, msg):
    global data

    print("Waw I got a message")
    try: 
        imu_vals = json.loads(msg.payload)
        # print(imu_vals)
        data.append(imu_vals)
    except ValueError as err:
        print("Bad Boi")
    # print("imu data: ", imu_vals)


def setup(hostname: str) -> mqtt.Client:
    client = mqtt.Client()
    client.on_connect = on_connect
    client.on_message = on_message

    client.connect(hostname, 1883)
    client.loop_start()
    # client.loop_forever()
    return client

def main():
    global data
    global slouch
    global to_send
    interval = []
    slouch_data = []
    client = setup("localhost")
    fields = ["x", "y", "z", "gx", "gy", "gz"]
    while True:
        if len(data) >= 15:
            dct = data.copy()
            # print(interval)
            data.clear()
            x_vals = [list(d.values())[0] for d in dct]
            avg_x = sum(x_vals)/len(x_vals)
            y_vals = [list(d.values())[1] for d in dct]
            avg_y = sum(y_vals)/len(y_vals)
            z_vals = [list(d.values())[2] for d in dct]
            avg_z = sum(z_vals)/len(z_vals)
            gx_vals = [list(d.values())[3] for d in dct]
            avg_gx = sum(gx_vals)/len(gx_vals)
            gy_vals = [list(d.values())[4] for d in dct]
            avg_gy = sum(gy_vals)/len(gy_vals)
            gz_vals = [list(d.values())[5] for d in dct]
            avg_gz = sum(gz_vals)/len(gz_vals)


            if(avg_x > -0.05 and avg_x < 0.002):  #Max	0.002, Min	-0.05
                slouch = 0
            elif(avg_x > -0.07 and avg_x <= -0.05):  #Max	-0.05, Min	-0.07
                slouch = 2
            elif(avg_x > -0.09 and avg_x <= -0.07): #Max  -0.07, Min	-0.09
                slouch = 1
            elif(avg_x > -0.17): #Max	-0.09, Min	-0.168666667
                slouch = 3
            else:
                slouch = 4

            slouch_data.append(slouch)

            if len(slouch_data) == 2:
                to_send = statistics.mode(slouch_data)
                print("Slouch: ", to_send)
                client.publish('imu/actuation', to_send)
                slouch_data.clear()

        time.sleep(0.001)

if __name__ == '__main__':
    main()
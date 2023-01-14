import paho.mqtt.client as mqtt
import json
import time
import csv

data = []

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
    interval = []
    client = setup("localhost")
    fields = ["x", "y", "z", "gx", "gy", "gz"]
    while True:
        # print("data len: ", len(data))
        if len(data) >= 15:
            interval = data.copy()
            # print(interval)
            data.clear()
            with open(f"veryslouch_data.csv", "a", newline='') as f:
                writer = csv.DictWriter(f, fieldnames=fields)
                for i in range(15):
                    writer.writerow(interval[i])
                print("written")
        time.sleep(0.001)

if __name__ == '__main__':
    main()
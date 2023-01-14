from flask import Flask, request, jsonify
from flask import render_template
import paho.mqtt.client as mqtt
from flask_mqtt import Mqtt

app = Flask(__name__)
# app.config['MQTT_BROKER_URL'] = '192.168.138.141'
# app.config['MQTT_BROKER_PORT'] = 1883
# app.config['MQTT_USERNAME'] = ''  # Set this item when you need to verify username and password
# app.config['MQTT_PASSWORD'] = ''  # Set this item when you need to verify username and password
# app.config['MQTT_KEEPALIVE'] = 5  # Set KeepAlive time in seconds
# app.config['MQTT_TLS_ENABLED'] = False  # If your server supports TLS, set it True
# topic = 'imu/actuation'

# mqtt_client = Mqtt(app)

@app.route('/getPayload')
def getPayload():
    return jsonify({'payload': payload_value})

# @mqtt_client.on_connect()
# def handle_connect(client, userdata, flags, rc):
#    if rc == 0:
#        print('Connected successfully')
#        mqtt_client.subscribe(topic) # subscribe topic
#    else:
#        print('Bad connection. Code:', rc)

# @mqtt_client.on_message()
# def handle_mqtt_message(client, userdata, message):
#    data = dict(
#        topic=message.topic,
#        payload=message.payload.decode()
#   )
#    print('Received message on topic: {topic} with payload: {payload}'.format(**data))
#    global payload_value
#    payload_value = data['payload']


@app.route('/')
def rendHTML():
    return render_template("index.html")

if __name__ == "__main__":
    app.run()
    
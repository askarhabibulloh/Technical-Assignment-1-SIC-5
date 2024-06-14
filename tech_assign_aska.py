from flask import Flask, request, jsonify

app = Flask(__name__)

@app.route('/api/data', methods=['POST'])
def terima_data():
    try:
        data = request.get_json()

        temperature = data.get('temperature')
        humidity = data.get('humidity')
        gas = data.get('gas')

        if temperature is None or humidity is None or gas is None:
            return jsonify({"error": "Invalid data"}), 400

        print(f"Data yang diterima - Temperature: {temperature}, Humidity: {humidity}, Gas: {gas}")

        return jsonify({"message": "Data received successfully"})

    except Exception as e:
        return jsonify({"error": str(e)}), 500

if __name__ == '__main__':
    app.run(host='0.0.0.0', port=5001)


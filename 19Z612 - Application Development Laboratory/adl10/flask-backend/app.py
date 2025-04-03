from flask import Flask, jsonify, request
import mysql.connector

app = Flask(__name__)

# MySQL Database Connection
db = mysql.connector.connect(
    host="localhost",
    user="root",
    password="root_password",
    database="prettypaper"
)
cursor = db.cursor(dictionary=True)

@app.route('/wallpapers', methods=['GET'])
def get_wallpapers():
    quality = request.args.get('quality')
    dimensions = request.args.get('dimensions')

    query = "SELECT * FROM wallpapers"
    filters = []

    if quality:
        filters.append(f"quality = '{quality}'")
    if dimensions:
        filters.append(f"dimensions = '{dimensions}'")

    if filters:
        query += " WHERE " + " AND ".join(filters)

    cursor.execute(query)
    wallpapers = cursor.fetchall()
    return jsonify(wallpapers)

@app.route('/add_wallpaper', methods=['POST'])
def add_wallpaper():
    data = request.json
    cursor.execute(
        "INSERT INTO wallpapers (url, quality, dimensions) VALUES (%s, %s, %s)",
        (data['url'], data['quality'], data['dimensions'])
    )
    db.commit()
    return jsonify({"message": "Wallpaper added"}), 201

if __name__ == '__main__':
    app.run(host="0.0.0.0", port=5080, debug=True)

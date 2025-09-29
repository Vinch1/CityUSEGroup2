from flask import Flask, request
import sqlite3

app = Flask(__name__)

@app.route('/login')
def login():
    # 危险：直接拼接用户输入到 SQL 查询中
    username = request.args.get('username')
    password = request.args.get('password')
    
    conn = sqlite3.connect('users.db')
    cursor = conn.cursor()
    
    # ❌ 严重漏洞：SQL 注入
    query = f"SELECT * FROM users WHERE username='{username}' AND password='{password}'"
    cursor.execute(query)
    
    user = cursor.fetchone()
    conn.close()
    
    if user:
        return "登录成功！"
    else:
        return "登录失败！"

if __name__ == '__main__':
    app.run(debug=True)

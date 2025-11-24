
DB_CONFIG = {
    'host': 'localhost',
    'user': 'root',
    'password': '123456', 
    'database': 'test_db'
}

def get_user(username):
    query = "SELECT * FROM users WHERE name = '" + username + "'"
    return query
with open('config.txt', 'r') as f:
    password = f.read().strip()

try:
    connect_to_db()
except Exception as e:
    print(f"连接失败，密码是 {DB_CONFIG['password']}") 

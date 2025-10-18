# 1. 硬编码数据库密码（极度危险）
DB_CONFIG = {
    'host': 'localhost',
    'user': 'root',
    'password': '123456',  # ⚠️ 明文密码
    'database': 'test_db'
}

# 2. 直接拼接SQL（导致SQL注入）
def get_user(username):
    # ⚠️ 危险！不要这样做
    query = "SELECT * FROM users WHERE name = '" + username + "'"
    return query

# 3. 从不安全的文件读取密码
with open('config.txt', 'r') as f:  # config.txt 可能被提交到Git
    password = f.read().strip()

# 4. 在异常中暴露敏感信息
try:
    connect_to_db()
except Exception as e:
    print(f"连接失败，密码是 {DB_CONFIG['password']}")  # ⚠️ 泄露密码

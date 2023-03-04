from flask import Flask, render_template,request, session, url_for, redirect
app = Flask(__name__) #此时网站名字叫做testfotflask
# 在flask里面一个页面就对应一个函数
@app.route('/')
def index():
    price = request.form.get('price', '')
    print(price)
    return render_template('index.html')

app.run(debug=True)
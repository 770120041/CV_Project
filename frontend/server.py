from flask import Flask, request, jsonify, send_from_directory, render_template
import base64
import subprocess

app = Flask(__name__, static_url_path='')

@app.route('/static/<path:path>')
def send_static(path):
    return send_from_directory('static', path)

@app.route('/')
@app.route('/index.html')
def index():
   return send_from_directory('static', 'index.html')

@app.route('/result.png')
def result():
    return send_from_directory('.', 'compositeimage.png')

def write_image(name, data):
    head, content = data.split(',')
    type = head.split('/')[1].split(';')[0]
    filename = name
    if type == 'png':
        filename += ".png"
    else:
        filename += ".jpg"
    with open("temp/" + filename, "wb") as fh:
        fh.write(base64.b64decode(content))
    return filename

@app.route("/submit", methods=['POST'])
def submit():
    req = request.get_json()
    n = len(req['images'])
    imgs = ""
    labels = ""
    for i in range(n):
        f1 = write_image("%d_img" % i, req['images'][i])
        f2 = write_image("%d_tag_img" % i, req['tagImages'][i])
        imgs += " temp/" + f1
        labels += " temp/" + f2
    func = req['func']
    bashCommand = "./project_cml 0 %s %s %s" % (func, imgs, labels)
    print(bashCommand)
    process = subprocess.Popen(bashCommand.split(), stdout=subprocess.PIPE)
    output, error = process.communicate()
    return jsonify({"result": "ok"})
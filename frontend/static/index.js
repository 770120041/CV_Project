const uploadInput = document.getElementById('upload-input');
const imageContainer = document.getElementById('images-container');
const editorCanvas = document.getElementById('editor-canvas');
const backgroundImage = document.getElementById('background-image');
const hiddenImage = document.getElementById('hidden-image');
const alertBar = document.getElementById('alert-bar');
const editorCanvasCtx = editorCanvas.getContext('2d');
const images = [];
const tagImages = [];
let selectedId = 0;
let lineSize = 20;
let drawFlag = false;

uploadInput.addEventListener('change', async function(e){
    if(e.target.files.length === 0){
        return;
    }
    const oldLen = images.length;
    for(const file of e.target.files){
        images.push(await new Promise((res, rej) => {
            const reader = new FileReader();
            reader.onload = function(x){ console.log(x); res(x.target.result); }
            reader.onerror = rej;
            reader.readAsDataURL(file);
        }));
    }
    // size of image check
    applyImageTo(hiddenImage, images[0]);
    const h = hiddenImage.height;
    const w = hiddenImage.width;
    for(let i = oldLen; i < images.length; i++){
        applyImageTo(hiddenImage, images[i]);
        const nh = hiddenImage.height;
        const nw = hiddenImage.width;
        if(nh !== h || nw !== w){
            // TODO:: check failed
        }
    }
    editorCanvas.height = h;
    editorCanvas.width = w;
    cleanCanvas();
    console.log(images.length);
    const emptyImage = editorCanvas.toDataURL();
    console.log(emptyImage);
    for(let i = oldLen; i < images.length; i++) tagImages[i] = emptyImage;
    syncImages();
}, false);

function uploadImages(){
    uploadInput.click();
}
function syncImages(){
    imageContainer.innerHTML = images.map((image, i) => `
<div class="image-item">
    <div class="button-container">
        <button type="button" class="close" aria-label="Close" onclick="removeImage(${i})">
            <span aria-hidden="true">&times;</span>
        </button>
    </div>
    <img src="${image}" class="image-icon" onclick="selectImage(${i})">
</div>`).join("\n");
}
const HEIGHT_LIMIT = 768;
const WIDTH_LIMIT = 1024;
function applyImageTo(dst, src){
    dst.src = src;
    if(dst.height > HEIGHT_LIMIT){
        const ratio = dst.height / HEIGHT_LIMIT;
        dst.height = HEIGHT_LIMIT;
        dst.width = dst.width / ratio;
    }
    if(dst.width > WIDTH_LIMIT){
        const ratio = dst.width / WIDTH_LIMIT;
        dst.width = WIDTH_LIMIT;
        dst.height = dst.height / ratio;
    }
    editorCanvas.height = dst.height;
    editorCanvas.width = dst.width;
    editorCanvas.style.height = dst.height + "px";
    editorCanvas.style.width = dst.width + "px";
}
function selectImage(id){
    selectedId = id;
    cleanCanvas();
    applyImageTo(backgroundImage, images[id]);
    const image = new Image();
    image.onload = function() {
        editorCanvasCtx.drawImage(image, 0, 0);
    };
    image.src = tagImages[id]
}
function removeImage(id){
    selectImage(-1);
    for(let i = id; i < images.length - 1; i++){
        images[i] = images[i + 1];
        tagImages[i] = tagImages[i + 1];
    }
    images.pop();
    tagImages.pop()
    syncImages();
}
function cleanCanvas(){
    editorCanvasCtx.setTransform(1, 0, 0, 1, 0, 0);
    editorCanvasCtx.clearRect(0, 0, editorCanvasCtx.canvas.width, editorCanvasCtx.canvas.height);
}
editorCanvas.addEventListener('mouseup', function (e) {
    drawFlag = false;
    editorCanvasCtx.closePath();
    tagImages[selectedId] = editorCanvas.toDataURL();
});
editorCanvas.addEventListener('mousedown', function (e) {
    if(selectedId === -1){
        return;
    }
    drawFlag = true;
    editorCanvasCtx.lineJoin = 'round';
    editorCanvasCtx.lineCap = 'round';
    editorCanvasCtx.lineWidth = lineSize;
    editorCanvasCtx.strokeStyle = "red";
    editorCanvasCtx.beginPath();
    editorCanvasCtx.moveTo(e.offsetX, e.offsetY);
});
editorCanvas.addEventListener('mousemove', function (e) {
    if(drawFlag) {
        editorCanvasCtx.lineTo(e.offsetX, e.offsetY);
        editorCanvasCtx.stroke();
    }
});

function changeBrushSize(delta){
    lineSize += delta;
    if(lineSize <= 1) lineSize = 1;
}

function sumbitRequest(){
    const func = document.querySelector('#function-selector').value;
    alertBar.innerHTML = "Processing";
    fetch('/submit', {
        method: "POST",
        headers: {
            "Content-Type": "application/json",
        },
        body: JSON.stringify({
            func: func,
            images: images,
            tagImages: tagImages,
        })
    }).then((x) => x.json()).then((x) => {
        alertBar.innerHTML = "Finish";
        selectedId=-1
        const image = new Image();
        image.onload = function() {
            editorCanvasCtx.drawImage(image, 0, 0);
        };
        image.src = "/result.png"
    })
}

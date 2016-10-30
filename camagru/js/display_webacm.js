(function () {
  console.log('hello');
  var streaming = false,
video        = document.querySelector('#video'),
cover        = document.querySelector('#cover'),
width = 320,
height = 0;

if (!navigator.getUserMedia) {
  navigator.getUserMedia = (navigator.getUserMedia ||
    navigator.webkitGetUserMedia ||
    navigator.mozGetUserMedia ||
    navigator.msGetUserMedia)
}
if (navigator.getUserMedia) {
  navigator.getUserMedia({ video: true }, function(stream) {
    var video = document.querySelector('video');
    video.src = window.URL.createObjectURL(stream);
    console.log(stream)
    video.play()
  }, function(){
    console.log("votre webcam ne peut pas etre connecter")
  })
}

function takePicture() {
  console.log('in the fucntion')
    canvas.width = width;
  canvas.height = height;
  canvas.getContext('2d').drawImage(video, 0, 0, width, height);
  var data = canvas.toDataURL('image/png');
  photo.setAttribute('src', data);
}
window.takePicutre = takePicture

})()

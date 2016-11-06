(function () {
  console.log('hello')
  video        = document.querySelector('#video'),
cover        = document.querySelector('#cover'),
width = 250,
height = 250

  if (!navigator.getUserMedia) {
    navigator.getUserMedia = (navigator.getUserMedia ||
      navigator.webkitGetUserMedia ||
      navigator.mozGetUserMedia ||
      navigator.msGetUserMedia)
  }
if (navigator.getUserMedia) {
  navigator.getUserMedia({ video: true }, function(stream) {
    var video = document.querySelector('video')
    video.src = window.URL.createObjectURL(stream)
    console.log(stream)
    video.play()
  }, function(){
    console.log("votre webcam ne peut pas etre connecter")
  })
}

function takePic() {
  console.log('in the fucntion')
    canvas.width = width
    canvas.height = height
    canvas.getContext('2d').drawImage(video, 30, 30, width, height)
    var data = canvas.toDataURL('image/png')
    var image = document.createElement('img')
    image.src = data
    document.getElementById('new_image').value = ""
    document.getElementById('new_image').appendChild(image)


    //photo.setAttribute('src', data)
}
window.takePic = takePic

})()

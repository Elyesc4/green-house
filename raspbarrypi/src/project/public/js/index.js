var canvasContainerDiv1 = document.getElementById("canvas_container_div1");
var canvasContainerDiv2 = document.getElementById("canvas_container_div2");

var pot = document.getElementById("pot");
canvasContainerDiv2.style.height = (parseInt(getComputedStyle(canvasContainerDiv1).height) * 0.2) + "px"
console.log()
var context = pot.getContext("2d");

context.beginPath();
context.strokeStyle = "red";
context.moveTo(0, 0);
context.lineTo(1000, 0);
context.moveTo(1000, 0);
context.lineTo(0, 100);
context.stroke();

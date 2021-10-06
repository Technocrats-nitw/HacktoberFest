/* Toggle Animations */
const jstoggle = document.getElementById("js-toggle");
jstoggle.addEventListener("click", () => {
  const animations = document.getElementById("down");
  animations.style.animationPlayState =
    animations.style.animationPlayState == "paused" ? "running" : "paused";
  jstoggle.innerHTML =
    animations.style.animationPlayState == "paused" ? "Play" : "Pause";
  const animations2 = document.getElementById("up");
  animations2.style.animationPlayState =
    animations2.style.animationPlayState == "paused" ? "running" : "paused";
});

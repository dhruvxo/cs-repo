let ageEl = document.getElementById("age");

setInterval(() => {
	let time = (new Date() - new Date(1071372800000)) / (1000 * 60 * 60 * 24 * 365.25);
	ageEl.innerText = time.toString().substring(0, 12);
}, 50);
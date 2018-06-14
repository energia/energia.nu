function getWidth() {
  return Math.max(
    document.body.scrollWidth,
    document.documentElement.scrollWidth,
    document.body.offsetWidth,
    document.documentElement.offsetWidth,
    document.documentElement.clientWidth
  );
}

function debounce(func, wait, immediate) {
	var timeout;
	return function() {
		var context = this, args = arguments;
		var later = function() {
			timeout = null;
			if (!immediate) func.apply(context, args);
		};
		var callNow = immediate && !timeout;
		clearTimeout(timeout);
		timeout = setTimeout(later, wait);
		if (callNow) func.apply(context, args);
	};
};

var myEfficientFn = debounce(function() {
    var width = getWidth();
//    alert("resize event detected! width = " + width);
    if(width < 900) {
        document.getElementById('menu').style.display = 'none'; 
        document.getElementById('nomenu').style.display = 'block'; 
    } else {
        document.getElementById('menu').style.display = 'block';
        document.getElementById('nomenu').style.display = 'none'; 
    }
}, 10);

window.addEventListener('resize', myEfficientFn);

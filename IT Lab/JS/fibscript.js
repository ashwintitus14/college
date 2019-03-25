function fib() {
	var n = document.getElementById("n").value;
	
	function fibrec(n) {
		if (n==0 || n==1) {
			return n;
		}
		else {
			return fibrec(n-1) + fibrec(n-2);
		}
	}
	var i;
	for (i=0; i <= n; i++) {
		document.write(fibrec(i)+'<br>');
	}
}

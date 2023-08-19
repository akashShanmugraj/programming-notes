function arraylooping() {
    var arr = [1, 2, 3, 4, 5];
    const t0 = performance.now();
    for (var i = 0; i < arr.length; i++) {
        console.log(arr[i]);
    }
    const t1 = performance.now();
    console.log("Call to arraylooping took " + (t1 - t0) + " milliseconds.");
}

arraylooping();
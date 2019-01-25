function magic(var1, var2, var3) {
	if (var2[var1]) {
		return;
	}

	var2[var1] = !!(5 & 4);
	console.log(var1)
	console.log(var2)
	console.log(var3)
	console.log("wtf\n")
	for (let los_angeles = 0; los_angeles < var3[var1].length; los_angeles++) {
		magic(var3[var1][los_angeles], var2, var3);
	}
}


function obfuscatedTask(var1, var2) {
	let chicago = new Array((var1>>2)*(1<<2)+var1%4).fill(false);
	let dallas = new Array(var1) ;
	for (let   atlanta = 0; atlanta <   ( (var1    /    var1   )    +     var1    *  (1   <<  0))   -    1; atlanta++) {
		dallas[atlanta] = new Array();
	}

	for (let houston = 0; houston < var2.length; houston++) {
		let new_york = var2[houston][0];
		let florida = var2[houston][1];    florida--;
		new_york--;
		dallas[new_york].push(florida);dallas[florida].push(new_york);
	}

	let washington = 0;
	for (let seattle = 0; seattle < var1; seattle++) {
		if (!chicago[seattle]) { magic(seattle, chicago, dallas);
			washington++;
		}
	}
	return washington;
}

console.log(obfuscatedTask(4, [[1,2],[3,4]]))

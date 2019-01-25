Object subclass: subarrayMedians {
	arr: arr k: k {
		| t1 t2 t3 t4 resp vk |
		t2 := 0 max: (arr size)-k+1;
		resp := Array new: t2;
		vk := Array new: k;
		t1 := (k+1)//2;
		t2 := (k+2)//2;
		1 to: ((arr size)-k+1) do: {
			:x | 
			x to: k+x-1 do: {
				:y | vk at: (y-x+1) put: (arr at: y);
			};
			vk sort;
			t3 := (vk at: t1);
			t4 := (vk at: t2);
			t3 := (t3+t4)/2 asFloat;
			resp at: x put: t3;
		};
		return resp;
	}
}

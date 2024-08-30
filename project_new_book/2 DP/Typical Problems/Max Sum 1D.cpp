int maxRangeSum(vector<int> a){
	int sum = 0, ans = 0;
	for (int i = 0; i < a.size(); i++){
		if (sum + a[i] >= 0) {  
			sum += a[i];
		  ans = max(ans, sum);          
	  } else sum = 0;
	}
	return ans;
}

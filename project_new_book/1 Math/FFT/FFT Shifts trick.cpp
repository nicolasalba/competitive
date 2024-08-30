//FFT Trick, it very useful for shifts in the following:
// Sum j_0_to_n-1 a[j]*a[j+i]
// where i is the number of shifts, and 'a' is some array.

    auto copy = actual;
    reverse(all(copy));
    // be careful with doubles precision, so maybe NTT could be useful here.
    // mulitply is the method of FTT or NTT
    auto polinomy = multiply(actual, copy);
    ll m = actual.size();
    answer[0] = polinomy[m-1]; // 0 with m-1, 1 with m-2 =m-1
    for (int i = 1; i <= m-1; i++) { // 1 step no m-1 steps
        // 0 with m-2 is 1 step, 1 with m-3 is one then m-1-1, also the last one m-1 is with m-1
        // 0 with m-3 is 2 step, m-1 with m-1-1
        answer[i] = polinomy[m-1-i] + polinomy[2*(m-1)-i+1];
    }

/** 
 * Forward declaration of guess API.
 * @param  num   your guess
 * @return 	     -1 if num is lower than the guess number
 *			      1 if num is higher than the guess number
 *               otherwise return 0
 * int guess(int num);
 */

class Solution {
public:
    int guessNumber(int n,int m=1) {
        int mid=m+(n-m)/2;
        int g=guess(mid);
        if(g==-1)
            return guessNumber(mid-1,m);
        else if(g==1)
            return guessNumber(n,mid+1);
        else
            return mid;
        
    }
};
// Question Link ---> https://leetcode.com/problems/intersection-of-two-arrays
// Day #6
package main;
import java.util.*;

class main {
	public static void main(String []args) {
		Solution obj = new Solution();
		int nums1[] = new int[]{1,2,2,1};
		int nums2[] = new int[]{2,2};
		int res[] = new int[]{};
		res = obj.intersection(nums1, nums2);
		for(Integer i:res) {	
			System.out.println(i);
		}
	}
}

class Solution {
    public int[] intersection(int[] nums1, int[] nums2) {
		Set<Integer> a = new HashSet<Integer>();
		Set<Integer> b = new HashSet<Integer>();
		for(int i=0; i<nums1.length; i++) {
			a.add(nums1[i]);
		}
		
		for(Integer i:nums2 ) {
			b.add(i);
		}
		
		a.retainAll(b);
		int i = 0;
		int res[] = new int[a.size()];
		Iterator<Integer> it = a.iterator();
		while(it.hasNext()) {
			res[i] = it.next();
			i++;
		}
		return res;
    }
}
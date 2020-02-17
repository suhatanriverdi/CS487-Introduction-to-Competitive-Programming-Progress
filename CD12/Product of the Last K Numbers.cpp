// Question Link ---> https://leetcode.com/problems/product-of-the-last-k-numbers/
class ProductOfNumbers {
public:
    vector<int> prods = {1};
    ProductOfNumbers() {
        
    }

    void add(int num) {
   		if (num == 0) {
   			prods = {1};
   		}
   		else {
   			prods.push_back(prods.back() * num);
   		}
    }
    
    int getProduct(int k) {
    	if (k > prods.size() - 1) {
    		return 0;
    	}
		return prods.back() / prods[prods.size() - 1 - k];
    }
};
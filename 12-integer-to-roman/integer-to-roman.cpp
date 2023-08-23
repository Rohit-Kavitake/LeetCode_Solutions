class Solution {
public:
    string intToRoman(int num) {
    int numbers[] = {1,4,5,9,10,40,50,90,100,400,500,900,1000};
    string sym[] = {"I","IV","V","IX","X","XL","L","XC","C","CD","D","CM","M"};
    string result ="";
    int i=12;    
    while(num>0)
    {
      int div = num/numbers[i];
      num = num%numbers[i];
    //   cout << div<<"y " << num<<endl;
      while(div--)
      {
        // cout << "x " << div << sym[i];
        result += sym[i];
      }
      i--;
    }
    return(result);
    }
};
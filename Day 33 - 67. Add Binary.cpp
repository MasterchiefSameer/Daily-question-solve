// Bit Manupulation 
/*
Is Code mein kya ho raha hai? (Hinglish Breakdown)
    sum = bitA ^ bitB ^ carry:
        XOR gate "Odd 1s" detector hota hai.
        Agar teenon mein se ek ya teenon '1' hain, toh result 1 aayega.
        Agar do '1' hain (jaise 1+1), toh XOR use 0 kar dega (jo ki sahi hai).
    carry = (bitA & bitB) | (carry & (bitA ^ bitB)):
        Ye logic carry generate karta hai.
        (bitA & bitB) check karta hai ki kya dono inputs 1 hain?
        (carry & (bitA ^ bitB)) check karta hai ki kya purana carry 1 tha aur naye inputs mein se koi ek 1 hai?
        Dono mein se koi bhi condition true hui, toh naya carry = 1 ho jayega.

Complexity:
    Time: O(max(N,M)) — Jahan N,M strings ki lengths hain.
    Space: O(1) — Hum extra space sirf output string ke liye le rahe hain.
    */

   /*a="1010" aur b="1011" ka iteration step-by-step dekhte hain.

Is logic mein hum do main formula use kar rahe hain:

    Sum Bit: bitA⊕bitB⊕carry

    Carry Bit: (bitA&bitB)∣(carry&(bitA⊕bitB))

Iteration Breakdown

Hum piche se (right to left) shuru karenge:
a=1010,b=1011,carry=0
Step	bitA	bitB	Carry (In)	Sum Bit (A⊕B⊕C)	Carry (Out) Logic	res (String)
1	0	1	0	0⊕1⊕0=1	(0&1)∣(0&(0⊕1))=0	"1"
2	1	1	0	1⊕1⊕0=0	(1&1)∣(0&(1⊕1))=1	"10"
3	0	0	1	0⊕0⊕1=1	(0&0)∣(1&(0⊕0))=0	"101"
4	1	1	0	1⊕1⊕0=0	(1&1)∣(0&(1⊕1))=1	"1010"

Deep Dive into Carry (Out) Logic (Step 2 & 4):
Jab dono bits 1 hoton hain (1&1=1), toh carry generate hota hai.
    Step 2 mein: bitA=1, bitB=1. Yahan (1&1) wala part 1 ho gaya, isliye carry 1 ban gaya.
    Step 4 mein: Phir se bitA=1, bitB=1. Carry phir se 1 ban gaya.
Final Step:
Loop khatam hone ke baad, hamare paas ek Carry = 1 bacha hai.
*/
class Solution {
public:
    string addBinary(string a, string b) {
        string res = "";
        int i = a.length() - 1;
        int j = b.length() - 1;
        int carry = 0;

        while (i >= 0 || j >= 0 || carry) {
            int bitA = (i >= 0) ? a[i--] - '0' : 0;
            int bitB = (j >= 0) ? b[j--] - '0' : 0;

            // --- Bitwise Logic Start ---
            
            // 1. Current Sum bit: (bitA XOR bitB XOR carry)
            int sum = bitA ^ bitB ^ carry;
            res += (sum + '0');

            // 2. New Carry bit: (bitA AND bitB) OR (carry AND (bitA XOR bitB))
            // Matlab: Carry tab aayega jab koi bhi do bits '1' hon
            carry = (bitA & bitB) | (carry & (bitA ^ bitB));
            
            // --- Bitwise Logic End ---
        }

        reverse(res.begin(), res.end());
        return res;
    }
};



// 2nd Method: formal way with carry and sum calculation

/*
Iteration	Digit A	Digit B	Carry (In)	Total (A+B+C)	char c (Total % 2)	New Carry (Total / 2)	res (String)
Step 1	0	1	0	1	'1' (1%2)	0 (1/2)	"1"
Step 2	1	1	0	2	'0' (2%2)	1 (2/2)	"10"
Step 3	0	0	1	1	'1' (1%2)	0 (1/2)	"101"
Step 4	1	1	0	2	'0' (2%2)	1 (2/2)	"1010"
*/
class Solution {
public:
    string addBinary(string a, string b) {
        string result = "";
        int carry = 0;
        reverse(a.begin(), a.end());
        reverse(b.begin(), b.end());

        for (int i = 0; i < max(a.length(), b.length()); i++) {
            int digitA = i < a.length() ? a[i] - '0' : 0;
            int digitB = i < b.length() ? b[i] - '0' : 0;

            int total = digitA + digitB + carry;
            char c = (total % 2) + '0';
            result += c;
            carry = total / 2;
        }
        if (carry)
            result += '1';

        reverse(result.begin(), result.end());
        return result;
    }
};
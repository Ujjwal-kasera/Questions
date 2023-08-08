class Solution
{
public:
    int countDigitOne(int n)
    {
        int ans = 0;

        for (long power = 1; power <= n; power *= 10)
        //increment of power is done by 10 time as we divide the count of 1 in 10's slot as repetative
        {
            int divisor = power * 10;
            //applying simple hit and trial maths by observing the count of 1's
            int quotient = n / divisor;
            int remainder = n % divisor;
            if (quotient > 0){
                ans+= quotient*power;
            }
            //condition when remainder exceeds the power
            if (remainder >= power)
            {
                ans += min(remainder - power + 1, power);
            }
        }

        return ans;
    }
};
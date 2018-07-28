using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace reverseInteger
{
    class Program
    {
        static void Main(string[] args)
        {
            //int temp = int.MaxValue;
            //int num = temp * 2;
            //int num = -12010;
            Console.WriteLine(Reverse(1534236469));
        }

        public static int Reverse(int x)
        {
            if( (x * 2) / 2 != x)
            {
                return 0;
            }
            if (x >= 0)
            {
                return Reverse_sub(x);
            }
            else
            {
                return -Reverse_sub(-x);
            }
        }

        public static int Reverse_sub(int x)
        {
            int rev_x = 0;
            while (x / 10 != 0)
            {
                rev_x = rev_x * 10 + x % 10;
                x = x / 10;
            }
            rev_x = rev_x * 10 + x;
            return rev_x;
        }
    }
}

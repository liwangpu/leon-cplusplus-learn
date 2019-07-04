using System;
using System.Text;

namespace ConsoleApp1
{
    class Program
    {
        static void Main(string[] args)
        {

            StringBuilder build = new StringBuilder();

            for (long i = 0; i < 20000000000; i++)
            {
                build.Append("1");
            }



        }
    }
}

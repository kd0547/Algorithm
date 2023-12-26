class Program
{

    static void Main()
    {
        string n = Console.ReadLine();
        int size = (int.Parse(n) + 1);
        int lowSize = int.Parse(n);
        if (lowSize == 0) { Console.WriteLine(0); return; }
        if (lowSize == 1) { Console.WriteLine(1); return; }

        ulong[] ary = new ulong[size];
        ary[0] = 0;
        ary[1] = 1;
        int i = 2;


        for (; i < size; i++)
        {
            ary[i] = ary[i - 1] + ary[i - 2];
        }

        Console.WriteLine(ary[i - 1]);
    }
}

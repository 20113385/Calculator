using sytem;
using system.colleections.generic;
using system.linq;
using system.text;

namaspace coba2
{
    class program
    {
        static void main(string[]args);
        {
            double a, b;

            console.writer("masukan bilangan pertama : ");
            a = covert.tooldouble(console.readline());
            console.writer("masukan bilangan kedua : ");
            b = covert.tooldouble(console.readline());

            console.writerline("hasil penjumlahan " + (a + b));
            console.writerline("hasil pengurangan " + (a - b));
            console.writerline("hasil perkalian " + (a * b));
            console.writerline("hasil pembagian " + (a / b));

            console.readline();

        }
    }
}
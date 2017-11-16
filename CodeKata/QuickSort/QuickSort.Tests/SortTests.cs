using System;
using System.Linq;
using System.Text;
using Xunit;

namespace QuickSort.Tests
{
    public class SortTests
    {
        private string PrintArray(int[] i)
        {
            StringBuilder sb = new StringBuilder();
            sb.Append("[ ");
            foreach(int a in i)
            {
                sb.Append(a);
                sb.Append(" ");
            }
            sb.Append(" ]");
            return sb.ToString();
        }

        [Theory]
        [InlineData(new int[] { 1 }, new int[] { 1 })]
        [InlineData(new int[] { 2, 1 }, new int[] { 1, 2 })]
        public void Given_ValidArray_Expected_SortedArray(int[] i, int[] e)
        {
            int[] a = QuickSort.Sort(i);
            Assert.True(Enumerable.SequenceEqual(a, e), "Actual: " + PrintArray(a));
        }

        [Theory]
        [InlineData(null)]
        [InlineData(new int[] {})]
        public void Given_InvalidArray_Expected_ThrowArguementException(int[] i)
        {
            Assert.Throws<ArgumentException>(() => QuickSort.Sort(i));
        }
    }
}

/********************************
Simulated Annealing And Tabu
C# Console Application
*******************************/

using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace Tabu2
{
    class Program
    {
        static void Main(string[] args)
        {

            //Test Random Solution
            string s = getRandomSolution(4);
            Console.WriteLine("Random Solution   :" + s);
            // Test Calculate Cost
            Console.WriteLine("Calculate Cost    :" + calculateCost(s));
            // Test Calculate Neighbour
            Console.WriteLine("Calcu. One Neighb :" +calculateNeighbour(s));
            // Test Simulated Annealling
            Console.WriteLine("After Annealling  :" + anneal(s));
            Console.WriteLine("Cost Aft. Anneal  :" + calculateCost(anneal(s)));
            // Test Tabu
            Console.WriteLine("After Tabu        :" + tabu(s));
            Console.WriteLine("Cost After Tabu   :" + calculateCost(tabu(s)));

        }


        public static string tabu(string sCurrent)
        {
            int iterMax = 1000;
            string sBest = sCurrent;
            int i = 0;
            var tabuList = new List<string>();

            /* Initialize List */
            tabuList.Add(calculateNeighbour(sCurrent));
            tabuList.Add(calculateNeighbour(sCurrent));
            tabuList.Add(calculateNeighbour(sCurrent));

            while (i < iterMax)
            {
                int j = 0;
                sCurrent = calculateNeighbour(sCurrent);
                for (j = 0; j < tabuList.Count; j++)
                {

                    if (sCurrent != tabuList[j] && calculateCost(sCurrent) < calculateCost(tabuList[j]))
                    {
                        sBest = sCurrent;
                        tabuList.Add(sBest);
                    }

                }

                while (tabuList.Count > 3)
                {
                    tabuList.RemoveAt(0);
                }

                i++;
            }

            return sBest;
        }

        public static string anneal(string solution)
        {
            int old_cost = calculateCost(solution);
            double T = 1.0;
            double T_min = 0.00001;
            double alpha = 0.9;

            while (T > T_min)
            {
                int i = 1;
                while (i <= 100)
                {
                    string newsolution = calculateNeighbour(solution);
                    int new_cost = calculateCost(newsolution);
                    double ap = acceptance_probability(old_cost, new_cost, T);
                    Random random = new Random();
                    if (ap > random.NextDouble())// Between 0.0 and 1.0
                    {
                        solution = newsolution;
                        old_cost = new_cost;

                    }

                    i += 1;
                }

                T = T * alpha;
            }

            return solution;
        }



        public static string calculateNeighbour(string solution)
        {
            // Shuffle String
            string Neighbour = new string(solution.OrderBy(x => random.Next()).ToArray());
            return Neighbour;
        }

        /* Gets a random Solution Like 12|3 */
        public static string getRandomSolution(int size)
        {
          
            string randomSolution = "";
            for (int z = 0; z < size - 1; z++)
            {
                char v = Convert.ToChar(RandomNumber(1, size) + 48);
                randomSolution += v.ToString();
            }
            randomSolution += '|';
            // Shuffle String
            randomSolution = new string(randomSolution.OrderBy(x => random.Next()).ToArray());

            return randomSolution;
        }

        /* Calculates Cost Of Solution */
        public static int calculateCost(string solution)
        {
            string[] values = solution.Split('|');

            // job , job
            int[,] changeCost = new int[,] { { 0, 2, 4 }, { 5, 0, 6 }, { 7, 8, 0 } };

            // machine , job
            int[,] machinCost = new int[,] { { 4, 5, 3 }, { 8, 9, 3 } };

            int mycost = 0;
           
            for (int m = 0; m < values.Length; m++)
            {
                // *| and |*
                if (values[m].Length == 1)
                {
                    int x = values[m][0] - '0' - 1;
                    mycost += machinCost[m, x];
                }

                // |** and **| 
                else if (values[m].Length == 2)
                {
                    mycost += machinCost[m, values[m][0] - '0' - 1];
                    mycost += changeCost[values[m][0] - '0' - 1, values[m][1] - '0' - 1];

                    mycost += machinCost[m, values[m][1] - '0' - 1];

                }

                // ***| and |***
                else if (values[m].Length == 3)
                {

                    mycost += machinCost[m, values[m][0] - '0' - 1];
                    mycost += machinCost[m, values[m][1] - '0' - 1];
                    mycost += machinCost[m, values[m][2] - '0' - 1];

                    mycost += changeCost[values[m][0] - '0' - 1, values[m][1] - '0' - 1];
                    mycost += changeCost[values[m][1] - '0' - 1, values[m][2] - '0' - 1];

                }
            }
            return mycost;
        }

        
        /* Gives Random Number */
        private static readonly Random random = new Random();
        private static readonly object syncLock = new object();
        public static int RandomNumber(int min, int max)
        {
            lock (syncLock)
            { // synchronize
                return random.Next(min, max);
            }
        }

        public static double acceptance_probability(int old_cost, int new_cost, double T)
        {
            return Math.Exp((old_cost - new_cost) / T);
        }
    }
}

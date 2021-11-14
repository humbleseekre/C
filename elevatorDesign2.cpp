/*
Design Elevator system. And then write an algorithm for that Design such that, the user request
should be completed in logN time in a N story building with M elevators.
*/
class Program
{
    static void Main(string[] args)
    {                 
        var positions = new List<int> { 0, 0, 0, 3, 0, 5, 0, 0, 8, 0, 10, 0, 0, 0, 0, 0, 16 };
        Console.WriteLine(FindTheNearestElevator(positions, 15));
    }


    public static int FindTheNearestElevator(List<int> elevators, int target) 
    {
        var elevatorFloors = elevators.Where(e => e != 0).ToArray();
        return BinarySearch(elevatorFloors, target);
    }


    private static int BinarySearch(int[] array, int target)
    {
        var left = 0;
        var right = array.Length - 1;

        while (left <= right)
        {
            var middle = (left + right) / 2;

            if (array[middle] == target)
                return middle;

            if (target < array[middle])
                right = middle - 1;
            else
                left = middle + 1;
        }

        var elevatorIndex = FindTheNearestElevator(array, left, right, target);
        return array[elevatorIndex];
    }


    private static int FindTheNearestElevator(int[] elevators, int left, int right, int target)
    {
        if (left < 1 && right < 1)
            return 0;

        var rightFloorGap = target - elevators[right];
        var leftFloorGap = elevators[left] - target;

        if (rightFloorGap < leftFloorGap)
            return right;

        return left;
    }
}

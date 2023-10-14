func twoSum(nums []int, target int) []int {
var result []int
var resultF []int

	for i, v := range nums {
		ost := target - v

		for it, vt := range nums {
			if ost == vt && i != it {
				result = append(result, it, i)
				break
			}
			
		}
	}
	resultF = append(resultF,result[len(result)-2],result[len(result)-1])
	return resultF
}

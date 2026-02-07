/**
 * @param {number[]} nums
 * @param {Function} fn
 * @param {number} init
 * @return {number}
 */
var reduce = function(nums, fn, init) {
    let l = nums.length;
    if(l == 0) return init;
    let ans = init;
    for(let i = 0; i < l; i++){
        ans = fn(ans,nums[i]);
    }
    return ans;
};
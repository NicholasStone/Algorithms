// https://leetcode-cn.com/problems/is-unique-lcci/
/**
 * @param {string} astr
 * @return {boolean}
 */


// 解1: 哈希表
// var isUnique = function(astr) {
//     let hashtable = [];
//     for (const c of astr) {
//         if (hashtable[c.charCodeAt()] === 1) return false;
//         else hashtable[c.charCodeAt()] = 1;
//     }
//     return true;
// };


// 解2: 位运算. 用一个整形的每一位来来当作哈希表

var isUnique = function (astr) {
    let mark = 0;
    for (const c of astr) {
        let offset = 1 << c.charCodeAt() - 97;
        // console.log(offset.toString(2));
        if (mark & offset) {
            return false;
            // console.log((mark&offset).toString(2));
        }
        else{
            mark |= offset;
        }
    }
    return true;
}

// 测试
var string = ['leetcode', 'll', 'abc']

string.forEach(str => {
    console.log(isUnique(str));
})

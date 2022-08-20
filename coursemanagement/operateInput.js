// This js file:
// Split strings like: ABC|DEF -> ["ABC","DEF"]
// Convert new type to old type of input of weeks: 1-4,6-8 -> 1,2,3,4,6,7,8
// Convert Time to Session: 0645-0730 -> 1
function splitString(str) {
    str += '|'
    var arrayStr = new Array();
    var tempStr = '';
    for(var i = 0; i < str.length; i++) {
        if(str[i] == '|') {
            arrayStr.push(tempStr);
            tempStr = '';
        } else
            tempStr += str[i];
    }
    return arrayStr;
}

function extendWeek(str) {
    str += ',';
    var arrayNum = new Array();
    var tempNum = 0, tempNumPre = 0;
    var isTo = false;
    for(var i = 0; i < str.length; i++) {
        if(str[i] >= '0' && str[i] <= '9')
            tempNum = tempNum * 10 + (str[i] - '0');
        else if(str[i] == '-') {
            isTo = true;
            tempNumPre = tempNum;
            tempNum = 0;
        } else if(str[i] == ',') {
            if(isTo == false)
                arrayNum.push(tempNum);
            else
                for(var j = tempNumPre; j <= tempNum; j++)
                    arrayNum.push(j);
            tempNum = tempNumPre = 0;
            isTo = false;
        }
    }
    return arrayNum;
}

function convertPeriod(str) {
    var timeFirst = parseInt(str[0] + str[1] + str[2] + str[3]);
    var timeSecond = parseInt(str[5] + str[6] + str[7] + str[8]);
    var startPeriod = [645,730,0825,0920,1015,1100,1230,1315,1410,1505,1600,1645,2359];
    var endPeriod = [730,0815,0910,1005,1100,1145,1315,1400,1455,1550,1645,1730];
    var startOrd = 0, endOrd = 0;
    for(var i = 1; i < startPeriod.length; i++) {
        if(startPeriod[i - 1] <= timeFirst && timeFirst < startPeriod[i]) {
            startOrd = i;
            break;
        }
    }
    for(var i = 1; i < endPeriod.length; i++)
        if(endPeriod[i - 1] < timeSecond && timeSecond <= endPeriod[i]) {
            endOrd = i;
            break;
        }
    
    var string = '';
    string = startOrd + '-' + endOrd;
    return extendWeek(string);
}
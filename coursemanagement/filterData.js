// This js file does:
// Check all data and show which of them are fitted to customer's request
function checker() {
    var CourseCode = splitString(document.getElementById('hp_content').value);
    var Date = new Array();
    var Time = new Array();

    var DateInput = document.getElementsByName('study-day-choose');
    for(var i = 0; i < DateInput.length; i++)
        if(DateInput[i].checked != 0)
            Date.push(true);
        else
            Date.push(false);
    var TimeInput = document.getElementsByName('study-time-choose');
    for(var i = 0; i < TimeInput.length; i++)
        if(TimeInput[i].checked != 0)
            Time.push(true);
        else
            Time.push(false);
    for(var i = 0; i < returnDatabase.length; i++) {
        var countOk = 0, countNOk = 0;
        for(var j = 0; j < CourseCode.length; j++)
            if(CourseCode[j] == returnDatabase[i].CourseCode) {
                countOk++;
                break;
            }
        
        var TimeCourse = convertPeriod(returnDatabase[i].Time);
        for(var j = 0; j < TimeCourse.length; j++)
            if(Time[TimeCourse[j] - 1] == false) {
                countNOk++;
                break;
            }
        if(countNOk == 0)
            countOk++;
        
        if(Date[returnDatabase[i].Day - 2] == true)
            countOk++;
        
        if(countOk == 3)
            chooseData.push(returnDatabase[i]);
    }
}
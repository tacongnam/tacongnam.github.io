// This js file:
// import JSON file and convert them into returnDatabase
function onChange(event) {
    var reader = new FileReader();
    reader.onload = onReaderLoad;
    reader.readAsText(event.target.files[0]);
}

function onReaderLoad(event) {
    var jsonData = JSON.parse(event.target.result);
    for (var i = 0; i < jsonData.length; i++) {
        var counter = jsonData[i];
        returnDatabase.push(counter);
    }
    document.getElementById("start_course").disabled = false;
    document.getElementById("start_course_intro").disabled = false;
    document.getElementById("myFile1").disabled = true;
    loadCourse();
}

document.getElementById('myFile1').addEventListener('change', onChange);

function loadCourse() {
    document.getElementById("week-name").innerText = returnDatabase[0].week_name;
    document.getElementById("course-name").innerText = returnDatabase[0].course_name;
    total_timer = returnDatabase[0].course_time;
    timer = total_timer;
    var hours = Math.floor(total_timer / 60);
    var minutes = (total_timer - Math.floor(total_timer / 60) * 60);
    var openhours = '', openminutes = '';
    if (hours < 10)
        openhours = '0';
    if (minutes < 10)
        openminutes = '0';
    document.getElementById("count_down").innerText = openhours + hours + ':' + openminutes + minutes;
    document.getElementById("preparation-code").innerHTML = returnDatabase[0].preparation_code;

    var numpart = returnDatabase[0].parts_code.length;
    pre_button += numpart;
    var HTMLstring = "";
    for (var i = 0; i < numpart; i++) {
        HTMLstring += '<button class="tablinks" onclick="openCity(event,&apos;' + returnDatabase[0].parts_code[i] + '&apos;)" disabled>' + returnDatabase[0].parts_name[i] + '</button>'
    }
    document.getElementById("parts_code").innerHTML = HTMLstring;

    HTMLstring = "";
    for (var i = 0; i < numpart - 1; i++) {
        var sub_part_len = returnDatabase[0].course_content[i].length;
        HTMLstring += '<div id="' + returnDatabase[0].parts_code[i + 1] + '" class="tabcontent">';
        for (var j = 0; j < sub_part_len; j++) {
            var getElement = returnDatabase[0].course_content[i][j];

            HTMLstring += '<div class="instruction-part"><header>' + getElement.header + '</header>' + getElement.instruction + '</div>';

            if(getElement.question_content != "") {
                HTMLstring += '<div class="question"><div class="question-title">' + getElement.question_content + ' ' + getElement.answer_content + '</div>';
            
                HTMLstring += '<div class="question-note">' + getElement.answer_note + '</div></div>';
                
                HTMLstring += '<div class="check-status"><div class="part-instruction">' + getElement.part_instruction + '</div><button onclick="checkPart(' + (startPart.length + 1) + ')">' + getElement.button_show + '</button><div class="course-part"></div></div>';

                var answer_array = getElement.answer;
                pre_anslen = answer.length;
                for (var k = 0; k < answer_array.length; k++)
                    answer.push(answer_array[k]);
                
                if(answer_array.length > 0) {
                    startPart.push(pre_anslen);
                    endPart.push(answer.length - 1);
                } else {
                    startPart.push(-1);
                    endPart.push(-2);
                }

                points.push(getElement.points);
                max_score += points[points.length - 1];
            }
        }
        HTMLstring += '</div>';
    }
    document.getElementById("add_content_here").innerHTML = HTMLstring;
}
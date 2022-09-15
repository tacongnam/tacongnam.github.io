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
    if(hours < 10)
        openhours = '0';
    if(minutes < 10)
        openminutes = '0';
    document.getElementById("count_down").innerText = openhours + hours + ':' + openminutes + minutes;
    document.getElementById("preparation-code").innerHTML = returnDatabase[0].preparation_code;

    
    var numpart = returnDatabase[0].course_vocab_code.length;
    if(numpart == 0)
        document.getElementsByClassName('tablinks')[1].hidden = true;
    var HTMLstring = "";
    for (var i = 0; i < numpart; i++) {
        var getElement = returnDatabase[0].course_vocab_code[i];
        HTMLstring += '<div class="instruction-part"><header>' + getElement.header + '</header>' + getElement.instruction + '</div>'
            + '<div class="question"><div class="question-title">' + getElement.question_content + ' ' + getElement.answer_content +
            '</div><div class="question-note">' + getElement.answer_note + '</div></div><div class="check-status"><div class="part-instruction">'
            + getElement.part_instruction + '</div><button onclick="checkPart(' + (i + 1) + ')">' + getElement.button_show + '</button><div class="course-part"></div></div>';

        var answer_array = getElement.answer;
        for (var j = 0; j < answer_array.length; j++)
            answer.push(answer_array[j]);
        points.push(getElement.points);
        max_score += points[points.length - 1];
        startPart.push(getElement.answer_from);
        endPart.push(getElement.answer_to);
    }
    document.getElementById("Vocabulary").innerHTML = HTMLstring;
    numpart = returnDatabase[0].course_grammar_code.length;
    if(numpart == 0)
        document.getElementsByClassName('tablinks')[2].hidden = true;
    HTMLstring = "";
    for (var i = 0; i < numpart; i++) {
        var getElement = returnDatabase[0].course_grammar_code[i];
        HTMLstring += '<div class="instruction-part"><header>' + getElement.header + '</header>' + getElement.instruction + '</div>'
            + '<div class="question"><div class="question-title">' + getElement.question_content + ' ' + getElement.answer_content +
            '</div><div class="question-note">' + getElement.answer_note + '</div></div><div class="check-status"><div class="part-instruction">'
            + getElement.part_instruction + '</div><button onclick="checkPart(' + (i + 1) + ')">' + getElement.button_show + '</button><div class="course-part"></div></div>';

        var answer_array = getElement.answer;
        for (var j = 0; j < answer_array.length; j++)
            answer.push(answer_array[j]);
        points.push(getElement.points);
        max_score += points[points.length - 1];
        startPart.push(getElement.answer_from);
        endPart.push(getElement.answer_to);
    }
    document.getElementById("Grammar").innerHTML = HTMLstring;

    numpart = returnDatabase[0].course_reading_code.length;
    if(numpart == 0)
        document.getElementsByClassName('tablinks')[3].hidden = true;
    HTMLstring = "";
    for (var i = 0; i < numpart; i++) {
        var getElement = returnDatabase[0].course_reading_code[i];
        HTMLstring += '<div class="instruction-part"><header>' + getElement.header + '</header>' + getElement.instruction + '</div>'
            + '<div class="question"><div class="question-title">' + getElement.question_content + ' ' + getElement.answer_content +
            '</div><div class="question-note">' + getElement.answer_note + '</div></div><div class="check-status"><div class="part-instruction">'
            + getElement.part_instruction + '</div><button onclick="checkPart(' + (i + 1) + ')">' + getElement.button_show + '</button><div class="course-part"></div></div>';

        var answer_array = getElement.answer;
        for (var j = 0; j < answer_array.length; j++)
            answer.push(answer_array[j]);
        points.push(getElement.points);
        max_score += points[points.length - 1];
        startPart.push(getElement.answer_from);
        endPart.push(getElement.answer_to);
    }
    document.getElementById("Reading").innerHTML = HTMLstring;

    numpart = returnDatabase[0].course_listening_code.length;
    if(numpart == 0)
        document.getElementsByClassName('tablinks')[4].hidden = true;
    HTMLstring = "";
    for (var i = 0; i < numpart; i++) {
        var getElement = returnDatabase[0].course_listening_code[i];
        HTMLstring += '<div class="instruction-part"><header>' + getElement.header + '</header>' + getElement.instruction + '</div>'
            + '<div class="question"><div class="question-title">' + getElement.question_content + ' ' + getElement.answer_content +
            '</div><div class="question-note">' + getElement.answer_note + '</div></div><div class="check-status"><div class="part-instruction">'
            + getElement.part_instruction + '</div><button onclick="checkPart(' + (i + 1) + ')">' + getElement.button_show + '</button><div class="course-part"></div></div>';

        var answer_array = getElement.answer;
        for (var j = 0; j < answer_array.length; j++)
            answer.push(answer_array[j]);
        points.push(getElement.points);
        max_score += points[points.length - 1];
        startPart.push(getElement.answer_from);
        endPart.push(getElement.answer_to);
    }
    document.getElementById("Listening").innerHTML = HTMLstring;

    numpart = returnDatabase[0].course_speaking_code.length;
    if(numpart == 0)
        document.getElementsByClassName('tablinks')[5].hidden = true;
    HTMLstring = "";
    for (var i = 0; i < numpart; i++) {
        var getElement = returnDatabase[0].course_speaking_code[i];
        HTMLstring += '<div class="instruction-part"><header>' + getElement.header + '</header>' + getElement.instruction + '</div>'
            + '<div class="question"><div class="question-title">' + getElement.question_content + ' ' + getElement.answer_content +
            '</div><div class="question-note">' + getElement.answer_note + '</div></div><div class="check-status"><div class="part-instruction">'
            + getElement.part_instruction + '</div><button onclick="checkPart(' + (i + 1) + ')">' + getElement.button_show + '</button><div class="course-part"></div></div>';

        var answer_array = getElement.answer;
        for (var j = 0; j < answer_array.length; j++)
            answer.push(answer_array[j]);
        points.push(getElement.points);
        startPart.push(getElement.answer_from);
        endPart.push(getElement.answer_to);
    }
    document.getElementById("Speaking").innerHTML = HTMLstring;
    auto_stop = returnDatabase[0].auto_stop;
    pass_score = returnDatabase[0].pass_score;
}
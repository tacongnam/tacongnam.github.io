// Thay đổi thời gian học (theo giây)
var total_timer = 5400;
// Thay đổi thời gian học (theo giây)

var timer = total_timer, countDown;
var isLastRun = false;
var isRunning = false;
function firstLoad() {
    openCity(event, 'Introduction');
    for (var i = 3; i < document.getElementsByTagName("button").length; i++)
        document.getElementsByTagName("button")[i].disabled = true;
    for (var i = 0; i < document.getElementsByTagName("input").length; i++)
        document.getElementsByTagName("input")[i].disabled = true;
    document.getElementById("count_down").innerText = Math.floor(timer / 60) + ":" + (timer - Math.floor(timer / 60) * 60);
    document.getElementById("start_course").disabled = false;
    document.getElementById("start_course_intro").disabled = false;
}

function startTimer(state) { // 0: -> off / on with reset timer, 2: -> pause / on without reset timer
    if (state == 0 && timer < total_timer) {
        var xxx = setTimeout(function() {
            isLastRun = true;
            document.getElementById("status-noti").innerText = "Đang tự động chấm lại toàn bộ phần...";
            for(var i = 0; i < points.length; i++)
                checkPart(i + 1);
        }, 3100);
        var xxx = setTimeout(function() {
            document.getElementById("status-noti").innerText = "Đã hoàn thành bài thi";
        }, 10000);
        document.getElementById("start_course").innerText = "Đã kết thúc bài học";
        document.getElementById("pause_course").style.display = 'none';
        clearInterval(countDown);
        document.getElementById("pause_course").disabled = true;
        document.getElementById("start_course").disabled = true;
        isRunning = false;
        for (var i = 8; i < document.getElementsByTagName("button").length; i++)
            document.getElementsByTagName("button")[i].disabled = true;
        for (var i = 0; i < document.getElementsByTagName("input").length; i++)
            document.getElementsByTagName("input")[i].disabled = true;
    } else if(state == 2 && isRunning == true) {
        clearInterval(countDown);
        isRunning = false;
        for (var i = 8; i < document.getElementsByTagName("button").length; i++)
            document.getElementsByTagName("button")[i].disabled = true;
        for (var i = 0; i < document.getElementsByTagName("input").length; i++)
            document.getElementsByTagName("input")[i].disabled = true;
        document.getElementById("pause_course").innerText = "Tiếp tục bài học";
        document.getElementById("pause_course").disabled = false;
        document.getElementById("start_course").disabled = false;
    } else {
        if(state == 0)
            timer = total_timer;
        isRunning = true;
        document.getElementById("pause_course").style.display = 'initial';
        document.getElementById("myModal").style.display = "none";
        document.getElementById("start_course_intro").style.display = "none";
        for (var i = 3; i < document.getElementsByTagName("button").length; i++)
            document.getElementsByTagName("button")[i].disabled = false;
        for (var i = 0; i < document.getElementsByTagName("input").length; i++)
            document.getElementsByTagName("input")[i].disabled = false;
        document.getElementById("start_course").innerText = "Kết thúc bài học";
        document.getElementById("pause_course").disabled = false;
        document.getElementById("start_course").disabled = false;
        document.getElementById("pause_course").innerText = "Tạm dừng học";
        countDown = setInterval(function () {
            timer--;
            document.getElementById("count_down").innerText = Math.floor(timer / 60) + ":" + (timer - Math.floor(timer / 60) * 60);
            if (timer == 0)
                startTimer(0);
            else if((total_timer - timer) % 900 === 0) {
                startTimer(2);
                document.getElementById("myModal").style.display = "block";
            }
        }, 1000);
    }
}

// Thay đổi kết quả và điểm của từng phần (tổng 100)
var answer = ['six', 'fifteen', 'thirty-seven', 'forty-five', 'sixty-three', 'eighty-two', 'ninety-nine', 'thirteenth', 'eighteenth',
'thirty-fifth', 'forty-seventh', 'eighty-second', 'ninety-third', 'monday', 'thursday', 'saturday', 'tuesday', 'friday', 'sunday',
'wednesday', 'tuesday', 'twentieth', 'friday', 'thirtieth', 'friday', 'two', 'wednesday', 'twenty-one', 'wednesday', 'seven','2,4,6,8'
,'2,3,4','listens','washes','ticks','has','goes','misses','is','C','G','A','F','B','F','D','A','H','G'];
var points = [10,10,10,7,3,10,10,10,5,5,2,5,3,10];
var startPart = [0,7,13,20,-1,30,31,32,-1,-1,-1,39,-1,44];
var endPart = [6,12,19,29,-2,30,31,38,-2,-2,-2,43,-2,48];
// Thay đổi kết quả và điểm của từng phần (tổng 100)

var user_points = 0;
var countCorrect = 0;
function checkPart(id) {
    countCorrect = 0;
    var empty_input = false;
    var startId = startPart[id - 1];
    var endId = endPart[id - 1];
    for (var i = startId; i <= endId; i++) {
        if (document.getElementsByName("user_input")[i].value == "") {
            empty_input = true;
            break;
        }
        if (document.getElementsByName("user_input")[i].value === answer[i])
            countCorrect++;
    }
    if (countCorrect == endId - startId + 1) {
        user_points += points[id - 1];
        document.getElementById("user_points").innerText = user_points;
        document.getElementsByClassName("course-part")[id - 1].innerText = "Chính xác!";
        document.getElementsByTagName("button")[id + 8].disabled = true;
        document.getElementsByTagName("button")[id + 8].style.backgroundColor = "green";
        if(isLastRun == false)
            document.getElementById("status-noti").innerText = "Chính xác, +" + points[id - 1] + " điểm";
        var xxx = setTimeout(function() {
            document.getElementById("status-noti").innerText = "";
        }, 3000);
        points[id - 1] = 0;
    } else {
        if (empty_input == true)
            document.getElementsByClassName("course-part")[id - 1].innerText = "Hãy thực hiện toàn bộ các yêu cầu của đề.";
        else
            document.getElementsByClassName("course-part")[id - 1].innerText = "Trả lời sai. Hãy kiểm tra lại kết quả.";
        document.getElementsByTagName("button")[id + 8].style.backgroundColor = "red";
        if(isLastRun == false)
            document.getElementById("status-noti").innerText = "Kiểm tra lại kết quả";
        var xxx = setTimeout(function() {
            document.getElementById("status-noti").innerText = "";
        }, 3000);
    }
}

function openCity(evt, cityName) {
    var i, tabcontent, tablinks;
    tabcontent = document.getElementsByClassName("tabcontent");
    for (i = 0; i < tabcontent.length; i++) {
      tabcontent[i].style.display = "none";
    }
    tablinks = document.getElementsByClassName("tablinks");
    for (i = 0; i < tablinks.length; i++) {
      tablinks[i].className = tablinks[i].className.replace(" active", "");
    }
    document.getElementById(cityName).style.display = "block";
    evt.currentTarget.className += " active";
  }

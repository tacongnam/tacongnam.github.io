var countDown;
var isLastRun = false;
var isRunning = false;
function firstLoad() {
    openCity(event, 'Introduction');
    for (var i = pre_button + 1; i < document.getElementsByTagName("button").length; i++)
        document.getElementsByTagName("button")[i].disabled = true;
    for (var i = 0; i < document.getElementsByClassName("user_input").length; i++)
        document.getElementsByClassName("user_input")[i].disabled = true;
    var hours = Math.floor(timer / 60);
    var minutes = (timer - Math.floor(timer / 60) * 60);
    var openhours = '', openminutes = '';
    if(hours < 10)
        openhours = '0';
    if(minutes < 10)
        openminutes = '0';
    document.getElementById("count_down").innerText = openhours + hours + ':' + openminutes + minutes;
}

function startTimer(state) { 
    // 0: -> off / on with reset timer,
    // 1: -> resume without reset timer
    // 2: -> pause without reset timer
    if (state == 0 && timer < total_timer) {
        var xxx = setTimeout(function () {
            isLastRun = true;
            document.getElementById("status-noti").innerText = "Đang tự động chấm lại toàn bộ phần...";
            for (var i = 0; i < points.length; i++)
                checkPart(i + 1);
        }, 3100);
        closeFullscreen();
        var xxx = setTimeout(function () {
            if (user_points >= pass_score) {
                document.getElementById("status-noti").innerHTML = "Bạn đã qua bài thi với thời gian " + (total_timer - timer) + " giây!";
                document.getElementById("status-noti").style.color = "green";
            } else {
                document.getElementById("status-noti").innerHTML = "Bạn chưa qua bài thi. Nếu có thời gian hãy làm lại bài thi này!";
                document.getElementById("status-noti").style.color = "red";
            }
        }, 7000);
        document.getElementById("start_course").innerText = "Đã kết thúc bài học";
        document.getElementById("pause_course").style.display = 'none';
        clearInterval(countDown);
        document.getElementById("pause_course").disabled = true;
        document.getElementById("start_course").disabled = true;
        isRunning = false;
        for (var i = pre_button + 1; i < document.getElementsByTagName("button").length; i++)
            document.getElementsByTagName("button")[i].disabled = true;
        for (var i = 0; i < document.getElementsByClassName("user_input").length; i++)
            document.getElementsByClassName("user_input")[i].disabled = true;
    } else if (state == 2 && isRunning == true) {
        clearInterval(countDown);
        document.getElementById("myModal").style.display = "block";
    } else {
        if (state == 0) {
            timer = total_timer;
            openFullscreen();
        }
        isRunning = true;
        document.getElementById("pause_course").style.display = 'initial';
        document.getElementById("myModal").style.display = "none";
        document.getElementById("start_course_intro").style.display = "none";

        for (var i = 2; i < document.getElementsByTagName("button").length; i++)
            document.getElementsByTagName("button")[i].disabled = false;
        for (var i = 0; i < document.getElementsByClassName("user_input").length; i++)
            document.getElementsByClassName("user_input")[i].disabled = false;

        document.getElementById("start_course").innerText = "Kết thúc bài học";
        document.getElementById("pause_course").disabled = false;
        document.getElementById("start_course").disabled = false;
        document.getElementById("pause_course").innerText = "Tạm dừng học";
        countDown = setInterval(function () {
            timer--;
            var hours = Math.floor(timer / 60);
            var minutes = (timer - Math.floor(timer / 60) * 60);
            var openhours = '', openminutes = '';
            if(hours < 10)
                openhours = '0';
            if(minutes < 10)
                openminutes = '0';
            document.getElementById("count_down").innerText = openhours + hours + ':' + openminutes + minutes;
            if (timer == 0)
                startTimer(0);
            else if ((total_timer - timer) % auto_stop === 0) {
                startTimer(2);
            }
            if(user_points == max_score)
                startTimer(0);
        }, 1000);
    }
}

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
            document.getElementsByName("user_input")[i].style.backgroundColor = "#ffc3bf";
            continue;
        }
        if (document.getElementsByName("user_input")[i].value === answer[i]) {
            countCorrect++;
            document.getElementsByName("user_input")[i].style.backgroundColor = "#bfffc4";
        } else {
            document.getElementsByName("user_input")[i].style.backgroundColor = "#ffc3bf";
        }
    }
    if (countCorrect == endId - startId + 1) {
        user_points += points[id - 1];
        document.getElementById("user_points").innerText = user_points + ' / ' + max_score;
        document.getElementsByClassName("course-part")[id - 1].innerText = "Chính xác!";
        document.getElementsByClassName("checkBtn")[id - 1].disabled = true;
        document.getElementsByClassName("checkBtn")[id - 1].style.backgroundColor = "green";
        if (isLastRun == false)
            document.getElementById("status-noti").innerText = "Chính xác, +" + points[id - 1] + " điểm";
        for (var i = startId; i <= endId; i++)
            document.getElementsByName("user_input")[i].disabled = true;
            points[id - 1] = 0;
        var xxx = setTimeout(function () {
            document.getElementById("status-noti").innerText = "";
        }, 3000);
    } else {
        if (empty_input == true)
            document.getElementsByClassName("course-part")[id - 1].innerText = "Hãy thực hiện toàn bộ các yêu cầu của đề.";
        else
            document.getElementsByClassName("course-part")[id - 1].innerText = "Trả lời sai. Hãy kiểm tra lại kết quả.";
            document.getElementsByClassName("checkBtn")[id - 1].style.backgroundColor = "red";
        if (isLastRun == false)
            document.getElementById("status-noti").innerText = "Kiểm tra lại kết quả";
        var xxx = setTimeout(function () {
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

var elem = document.documentElement;

/* View in fullscreen */
function openFullscreen() {
  if (elem.requestFullscreen) {
    elem.requestFullscreen();
  } else if (elem.webkitRequestFullscreen) { /* Safari */
    elem.webkitRequestFullscreen();
  } else if (elem.msRequestFullscreen) { /* IE11 */
    elem.msRequestFullscreen();
  }
}

function closeFullscreen() {
    if (document.exitFullscreen) {
      document.exitFullscreen();
    } else if (document.webkitExitFullscreen) { /* Safari */
      document.webkitExitFullscreen();
    } else if (document.msExitFullscreen) { /* IE11 */
      document.msExitFullscreen();
    }
  }
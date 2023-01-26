var intervalVar;

function setTimer() {
    $(".info__clock").text("Timeleft: " + convertTime(course_length));
    initialCourseLength = course_length;
    $(".button-start-pause").click(function() {
        if (phase == "notStart") {
            phase = "starting";
            $(".blank-slide").hide();
            startTest();
            showToast("Đã bắt đầu bài học!");
            $(".button-start-pause").html(`<i class="fas fa-pause" style="font-size: 16px;"></i> Pause`);
            $(".button-end").removeAttr("disabled");
        } else if (phase == "starting") {
            phase = "pausing";
            clearInterval(intervalVar);
            $(".blank-slide").show();
            $(".info-container").css("z-index", 2);
            showToast("Đã tạm dừng bài học!");
            $(".button-start-pause").html(`<i class="fas fa-play" style="font-size: 16px;"></i> Continue`);
        } else if (phase == "pausing") {
            phase = "starting";
            startTest();
            $(".blank-slide").hide();
            $(".info-container").css("z-index", 2);
            showToast("Đã tiếp tục bài học!");
            $(".button-start-pause").html(`<i class="fas fa-pause" style="font-size: 16px;"></i> Pause`);
        }
    });
    $(".button-end").click(function() {
        phase = "pausing";
        clearInterval(intervalVar);
        $(".blank-slide").show();
        $(".info-container").css("z-index", 2);
        showToast("Đã tạm dừng bài học! (Tự động tạm dừng)");
        $(".button-start-pause").html(`<i class="fas fa-play" style="font-size: 16px;"></i> Continue`);

        $(".dialog__header--text").text("Xác nhận nộp bài");
        $(".dialog__content").html("Bạn có muốn nộp bài?<br><i>(Hệ thống đang tự động tạm dừng. Nhấn X để thoát hộp thoại rồi tiếp tục làm bài)</i>");
        $(".dialog__footer").show();
        $(".dialog__footer--button-right").removeClass("button-info");
        $(".dialog__footer--button-right").addClass("button-stop");
        $(".dialog__footer--button-right").text("Xác nhận");
        $(".dialog").show();
    })
}

var initialCourseLength = 0;

function startTest() {
    intervalVar = setInterval(function() {
        course_length--;
        $(".info__clock").text("Timeleft: " + convertTime(course_length));
        if (course_length == 0) {
            clearInterval(intervalVar);
            endTest();
        }
        if (course_length % break_time == 0) {
            phase = "pausing";
            clearInterval(intervalVar);
            $(".blank-slide").show();
            $(".info-container").css("z-index", 2);
            showToast("Đã tạm dừng bài học! (Tự động tạm dừng)");
            $(".button-start-pause").html(`<i class="fas fa-play" style="font-size: 16px;"></i> Continue`);
        }
    }, 1000);
}

function convertTime(time) {
    var getMinute = Math.floor(time / 60);
    if (getMinute < 10)
        getMinute = "0" + getMinute;
    var getSecond = Math.floor(time % 60);
    if (getSecond < 10)
        getSecond = "0" + getSecond;
    return getMinute + ":" + getSecond;
}

function endTest() {
    showToast("Nộp bài thành công!", "success");
    $(".button-end").attr("disabled", "");
    $(".button-start-pause").attr("disabled", "");
    try {
        calcMark();
    } catch (error) {
        $(".dialog__header--text").text("Lỗi!");
        $(".dialog__content").html("Lỗi chấm lại bài. Mã lỗi: " + error.message);
        $(".dialog__footer").hide();
        $(".dialog").show();
    }
    phase = "ending";
    $(".blank-slide").hide();
}
var courseChoose;

// Kiểm tra khi nhấn Load bài học
$(document).ready(function() {
    $(".dialog__footer--button-right").click(function() {
        if (phase == "selectingCourse") {
            var course_url = "";
            if ($("#file_json").val() != "" && $('input[name="loadCourseYesNo"]:checked').val() != undefined) {
                showToast("Vui lòng chỉ chọn một bài học (trên server hoặc từ máy tính)!", "error");
                return;
            } else if ($("#file_json").val() == "" && $('input[name="loadCourseYesNo"]:checked').val() == undefined) {
                showToast("Vui lòng chọn một bài học (trên server hoặc từ máy tính)!", "error");
                return;
            } else {
                if ($("#file_json").val() != "")
                    getJSONFromServer($("#file_json").val(), "local");
                else
                    getJSONFromServer($('input[name="loadCourseYesNo"]:checked').val(), "server");
                showToast("Đang tải bài học...");
                $(".dialog").hide();
                $(".loading-slide").show();
                $(".loading-slide--text").html("Đang tải dữ liệu bài học từ server...");
            }
        } else if (phase == "pausing") {
            clearInterval(intervalVar);
            endTest();
            $(".dialog__footer--button-right").removeClass("button-stop");
        }
    })
})

var lesson_name; // Tên bài học
var course_length; // Thời gian học
var break_time; // Thời gian nghỉ giữa giờ
var pass_score; // Điểm tối thiểu để qua môn
var judged = new Array();
// Load các dữ liệu bài học

function getJSONFromServer(course_link, type) {
    var errorCount = 0;
    intervalVar = setInterval(function() {
        errorCount += 500;
        if (intervalVar != undefined && errorCount > 5000) {
            $(".dialog__header--text").text("Lỗi!");
            $(".dialog__content").html("Lỗi lấy dữ liệu (server / local).");
            $(".dialog").show();
            $(".dialog__footer").hide();
            return;
        }
    }, 500);
    if (type == "server") {
        try {
            var xhttp = new XMLHttpRequest();
            xhttp.onreadystatechange = function() {
                console.log(xhttp);

                xhttp.onerror = function(e) {
                    alert("Unknown Error Occured. Server response not received.");
                };
            };
            $.ajax({
                async: false,
                url: course_link,
                type: "GET",
                dataType: "json",
                success: function(data) {
                    loadCourse(data, "server");
                },
                error: function(data) {
                    $(".loading-slide--text").html("Lỗi lấy dữ liệu từ server. Vui lòng truy cập lại sau!");
                }
            })
        } catch (error) {
            $(".dialog__header--text").text("Lỗi!");
            $(".dialog__content").html("Lỗi fetch dữ liệu (server). Mã lỗi: " + error.message);
            $(".dialog").show();
            $(".dialog__footer").hide();
        }
    } else {
        try {
            var file = $("#file_json")[0].files[0];
            var reader = new FileReader();
            reader.readAsText(file, "UTF-8");
            reader.onload = function(evt) {
                loadCourse(evt.target.result, "local");
            }
            reader.onerror = function(evt) {
                showToast("Lỗi đọc file từ máy tính", "error");
            }
        } catch (error) {
            $(".dialog__header--text").text("Lỗi!");
            $(".dialog__content").html("Lỗi fetch dữ liệu (local). Mã lỗi: " + error.message);
            $(".dialog").show();
            $(".dialog__footer").hide();
        }
    }
}

function loadCourse(data, type) {
    try {
        if (type == "local")
            data = JSON.parse(data);
    } catch (error) {
        $(".dialog__header--text").text("Lỗi!");
        $(".dialog__content").html("Lỗi đọc file JSON. Mã lỗi: " + error.message);
        $(".dialog").show();
        $(".dialog__footer").hide();
        return;
    }

    clearInterval(intervalVar);

    try {
        data = data[0];

        // Set initial value
        lesson_name = data.week_name + ": " + data.course_name;
        course_length = data.course_time;
        break_time = data.auto_stop;
        pass_score = data.pass_score;

        // Create navigation
        var navHTML = "";
        var loopId = 0;
        for (const coursePart of data.parts_code) {
            if (data.parts_name[loopId].length < 24) {
                navHTML += `<div class="navigation__block" value="` + data.parts_code[loopId] + `">
            <div class="navigation__block--text">` + data.parts_name[loopId] + `</div>
        </div>`;
            } else {
                navHTML += `<div class="navigation__block" value="` + coursePart + `">
            <div class="navigation__block--text navigation__block--longtext">` + data.parts_name[loopId] + `</div>
        </div>`;
            }
            loopId++;
        }

        $(".navigation").html(navHTML);

        // Add effect when hovering long text nav
        $(".navigation__block--longtext").hover(function() {
            var len = -this.innerHTML.length * 12.5 + 284;
            var tim = Math.min(this.innerHTML.length / 8, 7);
            document.documentElement.style.setProperty('--marquee-end-width', len + 'px');
            document.documentElement.style.setProperty('--marquee-time', tim + "s");
        });

        // Add show / hide
        $(".navigation__block").click(function() {
            $(".lesson__part").hide();
            var idShow = $(this).attr("value");
            $("#" + idShow).show();
        });

        // Create lesson content
        var lessonContentHTML = "";
        loopId = 0;
        questionId = 0;
        for (const courseContent of data.course_content) {
            lessonContentHTML += `
    <div class="lesson__part" id="` + data.parts_code[loopId] + `" style="display: none">
        <div class="lesson__content-header">` + data.parts_name[loopId] + `</div>
        `
            var innerLoopId = 0;
            for (const courseContentPart of courseContent) {
                lessonContentHTML += `
    <div class="lesson__content-subheader">
        ` + courseContentPart.header + `
    </div>
    <div class="lesson__content-passage">
        ` + courseContentPart.instruction + `
    </div> `;
                if (courseContentPart.question_content.length != 0) {
                    lessonContentHTML += `
    <div class="lesson__question">
        <div class="lesson__question-header">
            Question ` + ++questionId + `
        </div>
        <div class="lesson__question-content">
            ` + courseContentPart.question_content + `
            ` + courseContentPart.answer_content + `
        </div>
        <div class="lesson__question-constraint">
            ` + courseContentPart.answer_note + `
        </div>
        <div class="lesson__question-button">
        `;
                    if (courseContentPart.button_show.length != 0) {
                        lessonContentHTML += `
            <button class="button button-info lesson__button" id="` + (loopId * 2000 + innerLoopId) + `"> ` + courseContentPart.button_show + ` </button>
            `;
                    } else {
                        lessonContentHTML += `
            <button class="button button-info lesson__button" id="` + (loopId * 2000 + innerLoopId) + `" hidden> ` + courseContentPart.button_show + ` </button>
            `;
                    }
                    lessonContentHTML += `
            <div class="lesson__question-return-message"></div>
            <div class="lesson__question-response" style="display: none"> ` + courseContentPart.part_instruction + ` </div>
        </div>
    </div>
        `
                }
                innerLoopId++;
            }
            loopId++;
            lessonContentHTML += `</div>`;
        }

        $(".lesson__container").html(lessonContentHTML);

        $("img").click(function() {
            if ($(this).parents(".dialog").length != 0) {
                // img in dialog
                return;
            }
            $(".dialog__header--text").text("Ảnh");
            $(".dialog__content").html(`<img src="` + $(this).attr("src") + `" width="100%">`);
            $(".dialog__footer").hide();
            $(".dialog").show();
        });

        // When click button in study_container
        for (const courseContent of data.course_content) {
            var tempArray = new Array(courseContent.length);
            judged.push(tempArray);
        }

    } catch (error) {
        $(".dialog__header--text").text("Lỗi!");
        $(".dialog__content").html("File JSON không đúng định dạng bài thi. Mã lỗi: " + error.message);
        $(".dialog__footer").hide();
        $(".dialog").show();
        return;
    }

    $(".lesson__button").click(function() {
        var partNo = Math.floor($(this).attr("id") / 2000);
        var questNo = $(this).attr("id") % 2000;
        var correctAns = 0;
        var points = data.course_content[partNo][questNo].points;
        var idQuestion = 0;
        $(":input", $(this).parents(".lesson__question")[0]).each(function() {
            if ($(this).is(":button") == true)
                return;
            if (checkAnswer($(this).val(), data.course_content[partNo][questNo].answer[idQuestion]) == true) {
                $(this).css("border-color", "#019160");
                $(this).css("border-width", "2.5px");
                correctAns++;
            } else {
                $(this).css("border-color", "#ff4545");
                $(this).css("border-width", "2.5px");
            }
            idQuestion++;
        });

        try {
            judge(partNo, questNo, data.course_content[partNo][questNo].answer.length, correctAns, points);
        } catch (error) {
            $(".dialog__header--text").text("Lỗi!");
            $(".dialog__content").html("Lỗi chấm điểm. Mã lỗi: " + error.message);
            $(".dialog__footer").hide();
            $(".dialog").show();
            return;
        }

        if (data.course_content[partNo][questNo].answer.length > 0) {
            $(".lesson__question-return-message", $(this).parents(".lesson__question")[0]).text(correctAns + " / " + data.course_content[partNo][questNo].answer.length + " correct");
            if (correctAns > 0) {
                $(".lesson__question-return-message", $(this).parents(".lesson__question")[0]).removeClass("lesson__question-return-message--error");
                $(".lesson__question-return-message", $(this).parents(".lesson__question")[0]).addClass("lesson__question-return-message--success");
            } else {
                $(".lesson__question-return-message", $(this).parents(".lesson__question")[0]).removeClass("lesson__question-return-message--success");
                $(".lesson__question-return-message", $(this).parents(".lesson__question")[0]).addClass("lesson__question-return-message--error");
            }
        }
        $(".lesson__question-response", $(this).parents(".lesson__question")[0]).text(data.course_content[partNo][questNo].part_instruction);
    });


    $(".lesson__header").text(lesson_name);
    $(".question-input-get-classes").attr("autocomplete", "off");

    phase = "notStart";

    try {
        setTimer();
    } catch (error) {
        $(".dialog__header--text").text("Lỗi!");
        $(".dialog__content").html("Lỗi đặt đồng hồ. Mã lỗi: " + error.message);
        $(".dialog__footer").hide();
        $(".dialog").show();
        return;
    }

    setTimeout(function() {
        $(".loading-slide").hide();
        $(".blank-slide").show();
        $(".info-container").css("z-index", 2);
        $(".container").show();
        showToast("Tải bài học thành công!", "success");
    }, 1000);
    $(".loading-slide--text").html("Đã xong. Vui lòng đợi một chút...");
}
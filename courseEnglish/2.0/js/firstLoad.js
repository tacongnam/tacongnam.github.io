var timeoutToast;

// Tải xuống dữ liệu khởi đầu
function firstLoad() {
    $(".dialog").hide();
    $(".toast").hide();
    $(".container").hide();
    $(".blank-slide").hide();
    $(".dialog__header--close-button").click(function() {
        $(".dialog").hide();
    })
    $(document).ready(loadServer());
}

// Tải dữ liệu course list từ web
function loadServer() {
    // Đổi trạng thái thành đang chọn bài học
    phase = "selectingCourse";
    $(".loading-slide--text").html("Đang lấy dữ liệu các bài học từ server...");
    $.ajax({
        async: false,
        url: "https://tacongnam.github.io/courseEnglish/course-list.json",
        type: "GET",
        dataType: "json",
        success: function(data) {
            $(".dialog__header--text").text("Lựa chọn bài học của bạn:");
            var courseListTableHTML = `<b>Nhập file (JSON) từ máy: <input type="file" id="file_json"></b><br>
            <b>Hoặc, chọn các bài học có trên server:</b><br><table class=".dialog__table">
            <thead>
                <tr>
                    <th>STT</th>
                    <th>Tên bài học</th>
                    <th>Thời gian học</th>
                    <th>Thời gian nghỉ giữa giờ</th>
                    <th>Load bài học?</th>
                </tr>
            </thead>
            <tbody>`;
            var dataNo = 0;
            for (const courseRow of data) {
                courseListTableHTML += `<tr title='Chọn bài học muốn học'>
                    <td> ` + (++dataNo) + `</td>
                    <td> ` + courseRow.course_name + ` </td>
                    <td> ` + courseRow.course_time + ` </td>
                    <td> ` + courseRow.course_break + ` </td>
                    <td> <input type='radio' name='loadCourseYesNo' value='` + courseRow.course_link + `'/> </td>
                    </tr>`;
            }
            courseListTableHTML += `</tbody>
                                    </table>
                `;
            $(".dialog__content").html(courseListTableHTML);
            setTimeout(function() {
                $(".loading-slide").hide();
                $(".dialog").show();
            }, 1000);
            $(".dialog__footer--button-left").hide();
            $(".dialog__footer--button-right").html("Load bài học");
            $(".loading-slide--text").html("Đã xong. Vui lòng đợi một chút...");
        },
        error: function(data) {
            $(".dialog__header--text").text("Lựa chọn bài học của bạn:");
            var courseListTableHTML = `<b>Nhập file (JSON) từ máy: <input type="file" id="file_json"></b><br>
            <b>Hoặc, chọn các bài học có trên server:</b><br><p style="color: red">Lỗi dữ liệu từ server. Hãy:</p>
            <ol>
                <li>Kiểm tra đường truyền mạng của bạn.</li>
                <li>Xoá cache và truy cập lại trang web.</li>
                <li>Nếu không thể, tải file JSON từ server về và nhập từ máy. Tuy nhiên, <span style="color: red;">một số phần tử có thể không hoạt động được (video, âm thanh) nếu không có mạng.</span></li>
            </ol>
                `;
            $(".dialog__content").html(courseListTableHTML);
            setTimeout(function() {
                $(".loading-slide").hide();
                $(".dialog").show();
            }, 1000);
            $(".dialog__footer--button-left").hide();
            $(".dialog__footer--button-right").html("Load bài học");
            $(".loading-slide--text").html("Lỗi lấy dữ liệu từ server. Đang tải các phần còn lại...");
        }
    })
}

function showToast(message, type) {
    if (type == "error") {
        $(".toast").append(`
            <div class="toast__container">
                <div class="toast__content">
                    <div class="toast__content--text toast__content--error">
                        ` + message + `
                    </div>
                </div>
                <div class="toast__container--close-button"><i class="fas fa-times" style="font-size: 16px;" title="Close toast"></i></div>
            </div>
        `);
    } else if (type == "success") {
        $(".toast").append(`
            <div class="toast__container">
                <div class="toast__content">
                    <div class="toast__content--text toast__content--success">
                        ` + message + `
                    </div>
                </div>
                <div class="toast__container--close-button"><i class="fas fa-times" style="font-size: 16px;" title="Close toast"></i></div>
            </div>
        `);
    } else {
        $(".toast").append(`
            <div class="toast__container">
                <div class="toast__content">
                    <div class="toast__content--text">
                        ` + message + `
                    </div>
                </div>
                <div class="toast__container--close-button"><i class="fas fa-times" style="font-size: 16px;" title="Close toast"></i></div>
            </div>
        `);
    }

    $(".toast").show();

    timeoutToast = setTimeout(function() {
        $(".toast").children()[0].remove();
    }, 5000);

    $(".toast__container--close-button").click(function() {
        $(this).parent().remove();
    })

}

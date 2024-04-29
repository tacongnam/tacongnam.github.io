const hostUrl = window.location.href;
var blockedData = [];

async function fetchData() {
    fetch('https://tacongnam.github.io/coursemanagement/blockedlist.json')
        .then(function (response) {
            return response.text();
        })
        .then(function (html) {
            var json = JSON.parse(html);
            blockedData = json.data;
        })
        .then(function () {
            for (const x of blockedData) {
                if (x[0] == '')
                    return;
                var r = new RegExp(x[0]);
                if (r.test(hostUrl) == true) {
                    const pageContent = `<!DOCTYPE html>
                <html lang="en">
                <head>
                  <meta charset="UTF-8">
                  <meta name="viewport" content="width=device-width, initial-scale=1.0">
                  <title>Blocked Site</title>
                  <link rel="stylesheet" href="style.css">
                </head>
                <body>
                  <div class="background-container">
                    <img src="https://thumbs.dreamstime.com/z/rectangular-sign-board-text-access-denied-white-red-grunge-letters-respectively-white-background-access-denied-107177865.jpg" alt="Access Denied" class="background-image">
                    <div class="content-wrapper">
                      <h1>Bạn đã truy cập vào một trang web / từ khoá đang bị chặn</h1>
                      <table class="site-info">
                        <tbody>
                          <tr>
                            <th>URL:</th>
                            <td id="blocked-url">` + window.location.hostname + `</td>
                          </tr>
                          <tr>
                            <th>Tên:</th>
                            <td id="blocked-name">`+ x[1] + `</td>
                          </tr>
                          <tr>
                            <th>Lí do:</th>
                            <td id="blocked-reason">` + x[2] + `</td>
                          </tr>
                          <tr>
                            <th>Phân loại:</th>
                            <td id="blocked-category">` + x[3] + `</td>
                          </tr>
                        </tbody>
                      </table>
                    </div>
                  </div>
                </body>
                </html>
                `;

                    const pageStyling = `<style>body {
                    margin: 0;
                    display: flex;
                    justify-content: center;
                    align-items: center;
                    min-height: 100vh;
                    font-family: 'Open Sans', sans-serif;
                    font-size: 16px;  /* Set default font size */
                  }
                  
                  .background-container {
                    position: relative;
                  }
                  
                  .background-image {
                    opacity: 0.3;
                    position: absolute;
                    top: 0;
                    left: 0;
                    width: 100%;
                    height: 100%;
                  }
                  
                  .content-wrapper {
                    position: relative;
                    padding: 20px;
                    max-width: 600px;
                    margin: 0 auto;
                    background-color: rgba(255, 255, 255, 0.8);
                    border-radius: 5px;
                    box-shadow: 0px 2px 5px rgba(0, 0, 0, 0.1);
                    animation: fadeIn 0.5s ease-in-out forwards;
                  }
                  
                  @keyframes fadeIn {
                    from { opacity: 0; }
                    to { opacity: 1; }
                  }
                  
                  h1 {
                    text-align: center;
                    font-family: 'Roboto', sans-serif;
                    font-size: 24px;  /* Set heading font size */
                  }
                  
                  .site-info {
                    margin-top: 20px;
                    border-collapse: collapse;
                    width: 50%;
                    margin: 0 auto;
                  }
                  
                  .site-info th,
                  .site-info td {
                    padding: 10px;
                    font-size: 14px;  /* Set table text size */
                    border: 1px solid rgba(221, 221, 221, 0.5);
                  }
                  
                  .notification-emails {
                    margin-top: 20px;
                  }
                  
                  .notification-emails ul {
                    list-style: none;
                    padding: 0;
                  }
                  
                  .notification-emails li {
                    margin-bottom: 5px;
                  }</style>`;

                    document.head.innerHTML = pageStyling;
                    document.body.innerHTML = pageContent;

                    const notification = new Notification("Cảnh báo", { body: "Bạn đã truy cập vào một trang web / từ khoá đang bị chặn"});
                    break;
                }
            }
        })
        .catch(function (err) {
            console.log('Failed to fetch page: ', err);
        });
}

fetchData();
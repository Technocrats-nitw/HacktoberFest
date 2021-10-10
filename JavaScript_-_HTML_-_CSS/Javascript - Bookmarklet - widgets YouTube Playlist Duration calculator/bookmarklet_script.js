javascript: 
var countUdTime = 0;
/* for Desktop / laptop / youtube.com
   ===================================
   on YouTube Videos Page - https://www.youtube.com/channel/UCapQ8VzljfmUW5OM-ynsyCQ/videos
*/
/*  
    Check which youtube page and type user is open and select all the videos block
    ytt -> YouTube type [ Desktop | Mobile ]
    ytp -> Youtube Page [ Videos Page | Playlist Page | Watch Page]
*/
var ytt = "desktop";
/** select all the videos on youtube.com Videos Page*/
var ytp = document.querySelectorAll("ytd-grid-video-renderer");
if (ytp.length < 1) {
    /** select all the videos on youtube.com Playlist Page*/
    ytp = document.querySelectorAll("ytd-playlist-video-list-renderer > #contents > ytd-playlist-video-renderer");
}
if (ytp.length < 1) {
    /** select all the videos on youtube.com Watch Page*/
    ytp = document.querySelectorAll("ytd-playlist-panel-video-renderer");
}
if (ytp.length < 1) {
    /*
        for Mobile / m.youtube.com
        ==========================
    */ 
    ytt = "mobile";
    /** select all the videos on m.youtube.com Videos Page*/
    ytp = document.querySelectorAll("ytm-compact-video-renderer");
    if (ytp.length < 1) {
        /** select all the videos on m.youtube.com Playlist Page*/
        ytp = document.querySelectorAll("ytm-playlist-video-list-renderer > ytm-playlist-video-renderer");
    }
    if (ytp.length < 1) {
        /** select all the videos on m.youtube.com Watch Page*/
        ytp = document.querySelectorAll("ytm-playlist-panel-video-renderer");
    }
}

var time = 0;
for (var i = 0; i < ytp.length; i++) {
    try {
        /* get video duration/time from youtube video thumbnail block */
        if (ytt == "mobile") {
            var a = ytp[i].getElementsByTagName("ytm-thumbnail-overlay-time-status-renderer")[0].innerText;
        } else {
            var a = ytp[i].getElementsByTagName("ytd-thumbnail-overlay-time-status-renderer")[0].innerText;
        }
       /* convert h:m:s to seconds and add to total time */
        var tx = a.split(":");
        if (tx.length < 3) {
            time = time + Number(tx[0]) * 60 + Number(tx[1]);
        } else if ((tx.length = 3)) {
            time = time + Number(tx[0]) * 60 * 60 + Number(tx[1]) * 60 + Number(tx[2]);
        }
    } catch (e) {
        countUdTime = countUdTime + 1;
    }
}
/* Convert Seconds into H:M:S formate */
var ytpT = convertS(time);
/* Show alert message of output result */
var show = "YouTube Playlist \n --------------- \n Total Videos : " + ytp.length + "\n Total Duration : " + ytpT + "\n Avg. Duration  : " + convertS(time / ytp.length);
alert(show);
alert("Error to Get Time : " + countUdTime + " videos");


function convertS(sec) {
    var hrs = Math.floor(sec / 3600);
    var min = Math.floor((sec - hrs * 3600) / 60);
    var seconds = sec - hrs * 3600 - min * 60;
    seconds = Math.round(seconds * 100) / 100;
    var result = (hrs < 10 ? "0" + hrs : hrs) + " Hours ";
    result += (min < 10 ? "0" + min : min) + " Min ";
    result += (seconds < 10 ? "0" + seconds : seconds) + " Sec ";
    return result;
}
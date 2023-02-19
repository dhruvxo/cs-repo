let header = document.querySelector('#intro');
let anim = [
    { t: "{ }", ms: 200 },
    { t: "{_}", ms: 200 },
    { t: "{ }", ms: 200 },
    { t: "{_}", ms: 200 },
    { t: "{D_}", ms: 100 },
    { t: "{Dh_}", ms: 100 },
    { t: "{Dhr_}", ms: 100 },
    { t: "{Dhru_}", ms: 100 },
    { t: "{Dhruv_}", ms: 100 },
    { t: "{Dhruv }", ms: 100 },
    { t: "{Dhruv B}", ms: 100 },
    { t: "{Dhruv Bh_}", ms: 100 },
    { t: "{Dhruv Bha_}", ms: 100 },
    { t: "{Dhruv Bhat }", ms: 200 },
    { t: "{Dhruv Bhat_}", ms: 200 },
    { t: "{Dhruv Bhat}", ms: 200 },
    { t: "{Dhruv Bhat}", ms: 200 },

];
let stepDenominator = 1;
if (window.localStorage.stepDenominator)
    stepDenominator = window.localStorage.stepDenominator;
let i = 0;
let update = () => {
    let step = anim[i];
    header.innerText = step.t;
    i++;

    if (i < anim.length)
        setTimeout(update, step.ms / stepDenominator);
    else {
        header.classList.add('top');
        setTimeout(() => {
            document.getElementById('main').style.opacity = 1;
            initGlobe();
        }, 500);
        window.localStorage.stepDenominator = 2;
    }
}
update();
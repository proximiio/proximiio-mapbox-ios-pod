{

    /* ------------------------------------------------------------------------------------------ */
    /* Regular update */

    // Update turn instruction
    update_turn: ".{{direction}} {{distanceUnit}} {{distanceInt}} بعد",
    update_turn_left_hard: ".در الي أقصى اليسار",
    update_turn_left: ".در الي اليسار",
    update_turn_left_slight: ".در الي اليسار قليلاً",
    update_turn_straight: ".واصل التقدم الي الأمام",
    update_turn_right_slight: ".در الي اليمين قليلاً",
    update_turn_right: ".در الي اليمين",
    update_turn_right_hard: ".در الي أقصى اليمين",
    update_turn_around: ".در و توجه في الإتجاه المعاكس",
    update_destination: ".سوف تصل الي المكان المقصود",

    // Update level change instruction
    update_levelchange_elevator: ".{{levelTo}} إستخدم المصعد وتوجه الي {{distanceInt}} بعد ",
    update_levelchange_escalator: ".{{levelDirection}} استخدم السلم الكهربائي {{distanceUnit}} {{distanceInt}} بعد",
    update_levelchange_stairs: ".{{levelDirection}} الأدراج {{distanceUnit}} {{distanceInt}} بعد ",

    /* ------------------------------------------------------------------------------------------ */
    /* Immediate update */

    // Immediate instruction
    immediate_turn_left_hard: "در الي أقصى اليسار",
    immediate_turn_left: ".در الي اليسار",
    immediate_turn_left_slight: ".در الي اليسار قليلاً",
    immediate_turn_straight: ".واصل التقدم الي الأمام",
    immediate_turn_right_slight: ".در الي اليمين قليلاً",
    immediate_turn_right: ".در الي اليمين",
    immediate_turn_right_hard: ".در الي أقصى اليمين",
    immediate_turn_around: ".در و توجه في الإتجاه المعاكس",

    // Immediate level change instruction
    // {{distanceInt}}, {{distanceDec}}, {{distanceUnit}}, {{headingTo}}, {{headingDirection}}
    immediate_levelchange_elevator: ".{{levelTo}} الي الطابق {{headingDirection}} إستخدم المصعد",
    immediate_levelchange_escalator: ".{{direction}} إستخدم السلم الكهربائي",
    immediate_levelchange_stairs: ".{{levelTo}} الي الطابق {{direction}} إستخدم الأدراج",
    direction_up: "صعوداً",
    direction_down: "نزولاً",
    immediate_levelchange_side_left: "الي يسارك",
    immediate_levelchange_side_right: "الي يمينك",
    immediate_levelchange_side_ahead: "أمامك",

    /* ------------------------------------------------------------------------------------------ */
    /* Information about next step | used with Immediate instructions */

    // {{distanceInt}}, {{distanceDec}}, {{distanceUnit}}
    next_step_destination: ".{{distanceUnit}} {{distanceInt}} ثم تصل الي المكان المقصود بعد ",

    // {{distanceInt}}, {{distanceDec}}, {{distanceUnit}}, {{hasPassingLandmarks}}, {{#hasTowardsLandmarks}} {{/hasTowardsLandmarks}}
    // {{#passingLandmarks}}: {{landmark}}, {{landmarkPosition}} {{isFirst}} {{isLast}} {{/passingLandmarks}}
    // {{#towardsLandmarks}}: {{landmark}}, {{isFirst}} {{isLast}} {{/towardsLandmarks}}
    next_step_landmarks: ".{{#towardsLandmarks}}{{landmark}}{{#notFirst}}{{#isLast}} و {{/isLast}}{{#notLast}} ,{{/notLast}}{{/notFirst}}{{/towardsLandmarks}}{{#hasTowardsLandmarks}} بإتجاه {{/hasTowardsLandmarks}}{{#passingLandmarks}}{{#notLast}} ,{{/notLast}}{{landmarkPosition}} {{landmark}}{{/passingLandmarks}}{{#hasPassingLandmarks}} بمحاذات {{/hasPassingLandmarks}}{{distanceUnit}} {{distanceInt}} ثم تقدم",
    next_step_landmarks_landmark_position_left: "إلي يسارك", // used with {{#passingLandmarks}}
    next_step_landmarks_landmark_position_right: "إلي يمينك", // used with {{#passingLandmarks}}

    // {{distanceInt}}, {{distanceDec}}, {{distanceUnit}}, {{levelchanger}}
    next_step_levelchanger_elevator: ".{{distanceUnit}} {{distanceInt}} ثم سوف تصل الي مصعد بعد", // possibly replace elevator with POI name?
    next_step_levelchanger_escalator: ".{{distanceUnit}} {{distanceInt}} ثم سوف تصل الي الدرج الكهربائي بعد", // --||--
    next_step_levelchanger_stairs: ".{{distanceUnit}} {{distanceInt}} ثم سوف تصل الي الأدراج بعد", // --||--

    // {{hours}}, {{degreesInt}}, {{degreesDec}}, {{levelchanger}}
    next_step_leave_levelchanger_elevator: ".{{nextStepHours}} ثم در الي إتجاه {{exitHours}} اخرج من المصعد بإتجاه",
    next_step_leave_levelchanger_escalator: "",
    next_step_leave_levelchanger_stairs: "",

    /* ------------------------------------------------------------------------------------------ */
    /* Landmark passsing */

    // {{#hasLeftLandmarks}} {{#hasRightLandmarks}}
    // {{#leftLandmarks}}: {{landmark}} {{meta}} {{/leftLandmarks}}
    // {{#rightLandmarks}}: {{landmark}} {{meta}} {{/rightLandmarks}}
    passing_landmark: ".{{#hasRightLandmarks}}الي يسارك{{/hasRightLandmarks}} {{#rightLandmarks}}{{landmark}}{{/rightLandmarks}} {{#hasLeftLandmarks}}{{#hasRightLandmarks}} ,{{/hasRightLandmarks}}الي يمينك{{/hasLeftLandmarks}} {{#leftLandmarks}}{{landmark}}{{/leftLandmarks}} أنت تمر بجانب",

    /* ------------------------------------------------------------------------------------------ */
    /* Other */

    // Destination
    destination_arriving: ".أنت تصل الي المكان المقصود",
    // {{destination}}, {{hours}}, {{degreesInt}}, {{degreesDec}}
    destination_arrived: ".{{hours}} بإتجاه الساعة {{destination}} لقد وصلت الي ",

    // Special states
    state_calculating: ".يجري الحساب",
    state_recalculating: ".يجري إعادة الحساب",
    state_route_not_found: ".لا يوجد مسار",
    state_canceled: ".تم إلغاء المسار",

    // Hazards
    // {{title}} {{side}}
    hazard: ".{{side}} {{title}} توقى من",
    hazard_side_left: "الي يسارك",
    hazard_side_right: "ألي يمينك",
    hazard_side_ahead: "أمامك",

    // Decision
    // {{title}}
    decision: ".{{title}} أنت الأن في",

    // Segments
    // {{title}}
    segment_enter: ".{{title}}أنت الأن في",
    segment_leave: ".{{title}} لقد خرجت من",

    // Heading corrections
    // {{hours}}, {{degreesInt}}, {{degreesDec}}
    heading_correction: ".{{hours}} صحح مسارك الي الساعة ",
    heading_start: ".{{hours}} إبدء مسارك بالإتجاه الي الساعة ",
    heading_wrong_way: ".إستدر. أنت تمشي بالإتجاه الخاطئ",

    // Level quantity strings
    level: {
        zero: "طوابق",
        one: "طابق",
        two: "طابقان",
        few: "طوابق",
        more: "طوابق",
        other: "طوابق"
    },

    // Units
    'units:meter': {
        zero: "متر",
        one: "متر",
        two: "متران",
        few: "أمتار",
        more: "أمتار",
        other: "أمتار"
    },

    'units:step': {
        zero: "خطوة",
        one: "خطوة",
        two: "خطوتان",
        few: "خطوات",
        more: "خطوات",
        other: "خطوات"
    }

}

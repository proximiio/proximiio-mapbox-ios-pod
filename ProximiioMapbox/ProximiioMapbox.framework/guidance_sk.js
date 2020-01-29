{
    
    /* ------------------------------------------------------------------------------------------ */
    /* Regular update */
    
    // Update turn instruction
update_turn: "Za {{distanceInt}} {{distanceUnit}} {{direction}}.",
update_turn_left_hard: "odbočte prudko doľava",
update_turn_left: "odbočte doľava",
update_turn_left_slight: "odbočte mierne doľava",
update_turn_straight: "pokračujte rovno",
update_turn_right_slight: "odbočte mierne doprava",
update_turn_right: "odbočte doprava",
update_turn_right_hard: "odbočte prudko doprava",
update_turn_around: "sa odočte",
update_destination: "dorazíte do cieľa",
    
    // Update level change instruction
update_levelchange_elevator: "Za {{distanceInt}} {{distanceUnit}} použit výťah na poschodie {{levelTo}}.",
update_levelchange_escalator: "Za {{distanceInt}} {{distanceUnit}} použite eskalátor {{levelDirection}}.",
update_levelchange_stairs: "Za {{distanceInt}} {{distanceUnit}} použite schody {{levelDirection}}.",
    
    /* ------------------------------------------------------------------------------------------ */
    /* Immediate update */
    
    // Immediate instruction
immediate_turn_left_hard: "Odbočte prudko doľava.",
immediate_turn_left: "Odbočte doľava.",
immediate_turn_left_slight: "Odbočte mierne doľava.",
immediate_turn_straight: "Pokračujte rovno.",
immediate_turn_right_slight: "Odbočte mierne doľava.",
immediate_turn_right: "Odbočte doprava.",
immediate_turn_right_hard: "Odbočte prudko doprava.",
immediate_turn_around: "Otočte sa.",
    
    // Immediate level change instruction
    // {{distanceInt}}, {{distanceDec}}, {{distanceUnit}}, {{headingTo}}, {{headingDirection}}
immediate_levelchange_elevator: "Use the elevator {{headingDirection}} to level {{levelTo}}.",
immediate_levelchange_escalator: "Use the escalator {{direction}}.",
immediate_levelchange_stairs: "Use the stairs {{direction}} to level {{levelTo}}.",
direction_up: "up",
direction_down: "down",
immediate_levelchange_side_left: "on your left",
immediate_levelchange_side_right: "on your right",
immediate_levelchange_side_ahead: "ahead of you",
    
    /* ------------------------------------------------------------------------------------------ */
    /* Information about next step | used with Immediate instructions */
    
    // {{distanceInt}}, {{distanceDec}}, {{distanceUnit}}
next_step_destination: "Then you will reach your destination in {{distanceInt}} {{distanceUnit}}.",
    
    // {{distanceInt}}, {{distanceDec}}, {{distanceUnit}}, {{hasPassingLandmarks}}, {{hasTowardsLandmarks}}
    // {{#passingLandmarks}}: {{landmark}}, {{landmarkPosition}} {{isFirst}} {{isLast}} {{/passingLandmarks}}
    // {{#towardsLandmarks}}: {{landmark}}, {{isFirst}} {{isLast}} {{/towardsLandmarks}}
next_step_landmarks: "Potom pokračujte {{distanceInt}} {{distanceUnit}}{{#hasPassingLandmarks}} passing {{/hasPassingLandmarks}}{{#passingLandmarks}}{{landmark}} {{landmarkPosition}}{{#notLast}}, {{/notLast}}{{/passingLandmarks}}{{#hasTowardsLandmarks}} towards {{/hasTowardsLandmarks}}{{#towardsLandmarks}}{{#notFirst}}{{#notLast}}, {{/notLast}}{{#isLast}} and {{/isLast}}{{/notFirst}}{{landmark}}{{/towardsLandmarks}}.",
next_step_landmarks_landmark_position_left: "na ľavo", // used with {{#passingLandmarks}}
next_step_landmarks_landmark_position_right: "na pravo", // used with {{#passingLandmarks}}
    
    // {{distanceInt}}, {{distanceDec}}, {{distanceUnit}}, {{levelchanger}}
next_step_levelchanger_elevator: "Potom za {{distanceInt}} {{distanceUnit}} prídete ku výťahu.", // possibly replace elevator with POI name?
next_step_levelchanger_escalator: "Potom za {{distanceInt}} {{distanceUnit}} prídete ku eskalátoru.", // --||--
next_step_levelchanger_stairs: "Potom za {{distanceInt}} {{distanceUnit}} prídete ku schodom.", // --||--
    
    // {{hours}}, {{degreesInt}}, {{degreesDec}}, {{levelchanger}}
next_step_leave_levelchanger_elevator: "Exit elevator at {{exitHours}} o'clock and turn to {{nextStepHours}} o'clock.",
next_step_leave_levelchanger_escalator: "",
next_step_leave_levelchanger_stairs: "",
    
    /* ------------------------------------------------------------------------------------------ */
    /* Landmark passsing */
    
    // {{#hasLeftLandmarks}} {{#hasRightLandmarks}}
    // {{#leftLandmarks}}: {{landmark}} {{meta}} {{/leftLandmarks}}
    // {{#rightLandmarks}}: {{landmark}} {{meta}} {{/rightLandmarks}}
passing_landmark: "You are passing {{#leftLandmarks}}{{landmark}} {{meta}}{{/leftLandmarks}} {{#hasLeftLandmarks}}on your left{{#hasRightLandmarks}}, {{/hasRightLandmarks}}{{/hasLeftLandmarks}} {{#rightLandmarks}}{{landmark}} {{meta}}{{/rightLandmarks}} {{#hasRightLandmarks}}on your right{{/hasRightLandmarks}}.",
    
    /* ------------------------------------------------------------------------------------------ */
    /* Other */
    
    // Destination
destination_arriving: "You are arriving at the destination.",
destination_arrived: "You arrived at the destination.",
    
    // Special states
state_calculating: "Vypočítava sa.",
state_recalculating: "Prepočítava sa.",
state_route_not_found: "Cesta sa nenašla.",
state_canceled: "Cesta zrušená.",
    
    // Hazards
    // {{title}}
hazard: "Watch out for {{title}} {{side}}.",
hazard_side_left: "on your left",
hazard_side_right: "on your right",
hazard_side_ahead: "ahead of you",
    
    // Decision
    // {{title}}
decision: "You are at {{title}}.",
    
    // Segments
    // {{title}}
segment_enter: "You have entered {{title}}.",
segment_leave: "You are leaving {{title}}.",
    
    // Heading corrections
    // {{hours}}, {{degreesInt}}, {{degreesDec}}
heading_correction: "Correct your heading to {{hours}} o'clock",
heading_start: "Start route at your {{hours}} o'clock.",
    
    // Level quantity strings
level: {
one: "poschodie",
two: "poschodia",
few: "poschodia",
more: "poschodí",
other: "poschodí"
},
    
    // Units
    'units:meter': {
    one: "meter",
    two: "meters",
    few: "meters",
    more: "meters",
    other: "meters"
    },
    
    'units:step': {
    one: "krok",
    two: "kroky",
    few: "kroky",
    more: "krokov",
    other: "krokov"
    }
    
}

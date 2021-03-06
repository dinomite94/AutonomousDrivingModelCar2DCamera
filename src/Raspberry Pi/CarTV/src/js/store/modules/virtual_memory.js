// initial state, as return value, because copy is required
// access state through $store.state.virtual_memory.<property>
function initialState() {
    return {
        record_limit: 10,
        records: [],
    };

    /* record = {
        total
        available
    }
    */
}

// getters (for computed states)
const getters = {

};

// actions (async, usually call mutations)
// call with $store.dispatch('virtual_memory/<...>'[, args...])
const actions = {
    // ...
};

// mutations (can manipulate store)
// call with $store.commit('virtual_memory/<...>', value)
const mutations = {
    // resets to initial state
    reset(state) {
        const initState = initialState();
        for (const key in initState) {
            state[key] = initState[key];
        }
    },

    push(state, update) {
        state.records.push(update);

        while (state.records.length > state.record_limit) {
            state.records.shift();
        }
    },
};

export default {
    namespaced: true,
    state: initialState(),
    getters,
    actions,
    mutations,
};

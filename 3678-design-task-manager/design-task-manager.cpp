class TaskManager {
public:
    map<int, int> PriorityId; // TaskId, Priority
    map<int, int> UserId; // TaskId, UserId
    set<array<int, 3>> st; // priority, taskId, UserId
    TaskManager(vector<vector<int>>& tasks) {
        for(int i = 0; i < size(tasks); i++) {
            st.insert({tasks[i][2], tasks[i][1], tasks[i][0]});
            PriorityId[tasks[i][1]] = tasks[i][2];
            UserId[tasks[i][1]] = tasks[i][0];
        }
    }
    
    void add(int userId, int taskId, int priority) {
        st.insert({priority, taskId, userId});
        PriorityId[taskId] = priority;
        UserId[taskId] = userId;
    }
    
    void edit(int taskId, int newPriority) {
        rmv(taskId);
        PriorityId[taskId] = newPriority;
        add(UserId[taskId], taskId, newPriority);
    }
    
    void rmv(int taskId) {
        int p = PriorityId[taskId];
        st.erase(st.lower_bound({{p, taskId, -1}}));
    }
    
    int execTop() {
        
        if(st.empty())
            return -1;
        
        int userId = (*st.rbegin())[2];
        auto it = *st.rbegin();
        st.erase(st.find(it));
        
        return userId;
    }
};

/**
 * Your TaskManager object will be instantiated and called as such:
 * TaskManager* obj = new TaskManager(tasks);
 * obj->add(userId,taskId,priority);
 * obj->edit(taskId,newPriority);
 * obj->rmv(taskId);
 * int param_4 = obj->execTop();
 */
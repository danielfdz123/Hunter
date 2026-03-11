import React, { useEffect } from 'react';
import '../App.css';
import './tasks.css';
import AllTaskBox from '../Components/allTaskView';
import { useDispatch, useSelector } from 'react-redux';
import { fetchTasks, deleteTask as deleteTaskAction, addTask as addTaskAction } from '../Store/tasksSlice';

export function Tasks() {
  const dispatch = useDispatch();
  const tasks = useSelector((state) => state.tasks);

  // Gets tasks from store
  useEffect(() => {
    dispatch(fetchTasks());
  }, [dispatch]);

  // Deletes task from store
  const handleDeleteTask = (id) => {
    dispatch(deleteTaskAction(id));
  };

  // Prompts user to add a task then saves info in the STORE
  const addTask = async () => {
    let content = window.prompt("Enter task name:");
    let priority = window.prompt("Enter priority level (1-10):");

    if (content && priority) {
      const newTask = { content, priority }; // Adjust fields based on backend requirements
      await dispatch(addTaskAction(newTask)); // Ensure `addTaskAction` is correctly imported and used
    } else {
      alert("Both task name and priority level are required.");
    }
  };

  return (
    <>
      <div className="TaskPage">
        <h1 className="pageTitle">Our Goals!</h1>
        <div className="aboutBox">
          <b>
            Below, you will see a list of tasks that the task of <i>"<u>The Hangout</u>"</i> Minecraft server are currently working on! 
            Click on a task to see which person, or persons are responsible for said task! Click on the task name to see a more detailed view
            <br /> <br />
            Have a new project idea? Hit the <i>ADD TASK</i> button below to add to the list!
          </b>
        </div>
        <button id="add" onClick={addTask}>ADD TASK</button>
        <div className="allTasks">
          <AllTaskBox tasks={tasks} onDelete={handleDeleteTask} />
        </div>
      </div>
    </>
  );
}

export default Tasks;

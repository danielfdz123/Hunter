import React, { useState } from 'react';
import './allTaskView.css';

// Modal used for SINGLE task VIEW (shows task title, priority, and assigned employees)
const Modal = ({ isOpen, onClose, task }) => {
  if (!isOpen) return null;

  return (
    <div className="singTaskView">
      <div className="taskDetails">
        <h1>{task.content}</h1>
        <p> <u> Priority Level: <b> {task.priority}</b> </u> </p>
        <p> People responsible: </p>
        <ul>
          {task.employee ? (
            <p>• {task.employee.firstname} {task.employee.lastname}</p>
          ) : (
            <p> No one assigned. </p>
          )}
        </ul>
        <button onClick={onClose}>Close</button>
      </div>
    </div>
  );
};

const AllTaskBox = ({ tasks, onDelete }) => {
  const [modalOpen, setModalOpen] = useState(false);
  const [selectedTask, setSelectedTask] = useState(null);

  const openModal = (task) => {
    setSelectedTask(task);
    setModalOpen(true);
  };

  const closeModal = () => {
    setModalOpen(false);
    setSelectedTask(null);
  };

  const handleDeleteTask = (id) => {
    onDelete(id);
  };

  return (
    <div className="taskBox">
      {tasks.length === 0 ? (
        <p>No tasks found.</p>
      ) : (
        tasks.map((task) => (
          <div key={task.id} className="card">
            <div className="horizontal">
              <span className="title" onClick={() => openModal(task)}>
                <b> • <u>{task.content}</u> </b>
              </span>
              <span className='priority'> (Priority Level: {task.priority}) </span>
              <button onClick={() => handleDeleteTask(task.id)}>X</button>
            </div>
          </div>
        ))
      )}
      <Modal isOpen={modalOpen} onClose={closeModal} task={selectedTask} />
    </div>
  );
};

export default AllTaskBox;
